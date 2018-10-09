#include <stdio.h>
#include <stdlib.h>
#include <math.h>
	
int draw_shift[9] = {-12,7,0,12,19,24,28,31,36};

int gear_min,gear_max,note_min,note_max;

#define MIDI_A440_NOTE_NUMBER 57

int tablewidth,fs;
void calcular_tablamidi(double *tabla,int pasos)
{
     
     int i;
     double step = pow(2.0,1.0/12.0);
     
     for(i=0;i<pasos;i++)
	tabla[i] = 440.0*pow(step,i-MIDI_A440_NOTE_NUMBER);
     
     return;

}

void calcular_fsteps(double fbase, double *ftable, double *fsteps,int pasos)
//CALCULA LOS PASOS DE TABLA PARA GENERAR A PARTIR DE UNA FRECUENCIA BASE, 
//LAS FRECUENCIAS RESTANTES
{

    int i;
    for(i=0;i<pasos;i++)
	fsteps[i] = ftable[i]/fbase;
    
    return;

}


void imprimir_resultados(double *ftable, double *fsteps, int *qsteps, int pasos)
{
    int i;
    int low_fs = 0;
    printf("Nota MIDI\tf (Hz) \t\tSaltos\t\tSaltos(Q%d:16)\tNOTAS\n",tablewidth);
    for(i=0;i<pasos;i++){
	printf("%d: \t\t%lf \t%lf \t0x%08X \t\t",i,ftable[i],fsteps[i],qsteps[i]);
	if(ftable[i]*2.0 > (double)fs) {printf("(!) \n"); low_fs = 1;}
	else printf("\n");
	}
    
    if(low_fs) printf("\n (!) --> Frecuencias no generables debido a sampling muy bajo \n\n");
    return;

}

void calcular_qsteps(int *qsteps,double *fsteps,int pasos)
//CONVIERTE LOS VALORES DE PASO, DE FLOAT A Qx.16
{

    int i;
    for(i=0;i<pasos;i++)
	qsteps[i] = (int)(round(fsteps[i]*65536.0));
}


void notecalc_escribir_archivo(int gear_max,int gear_min,int *qsteps)
{

    int i;
    int pasos = gear_max - gear_min + 1;
    FILE *fp = NULL;
    fp = fopen("notecalc.h","w");
    if(fp == NULL) {printf("ERROR DE ARCHIVO.\n"); return;}
    fprintf(fp,"/*ARCHIVO GENERADO AUTOMATICAMENTE POR LA UTILIDAD NOTECALC. \nUTN-frbb 2017 Tecnicas Digitales 3.\n");
    fprintf(fp,"\n-- TABLA DE SALTOS FRACCIONALES, ORDENADOS POR NUMERO DE NOTA MIDI --\n\nDETALLES DE OPERACION:\n");
    fprintf(fp,"FRECUENCA DE MUESTREO: %d Hz.\nANCHO DE PALABRA DE TABLA: %d bits\nRESOLUCION FRACCIONAL; 16 bits*/\n\n",fs,tablewidth);
    fprintf(fp,"uint32_t qstep[%d] = { ",pasos);
    
    for(i=0;i<pasos;i++)
	{
	if(!(i&0x00000007)) fprintf(fp,"\n");
	
	if(i == pasos - 1) fprintf(fp,"0x%08X",qsteps[i+gear_min]);
	else fprintf(fp,"0x%08X,",qsteps[i+gear_min]);
	}
    
    fprintf(fp,"};\n");
    
    fclose(fp);
    fp = NULL;
    return;
}
	
void switchbox_escribir_archivo(int *switchbox,int notenum)
{

int i;
int pasos = notenum*9;
    
    FILE *fp = NULL;
    fp = fopen("switchbox.h","w");
    if(fp == NULL) 
	{
	printf("ERROR DE ARCHIVO.\n");
	return;
	}
    fprintf(fp,"/*ARCHIVO GENERADO AUTOMATICAMENTE POR LA UTILIDAD SWITCHBOX. \nUTN-frbb 2017 Tecnicas Digitales 3.\n");
    fprintf(fp,"\n-- TABLA DE 9 CONTACTOS POR NOTA MIDI  --\n\nDETALLES DE OPERACION:\n");
    fprintf(fp,"NOTA MAS GRAVE %d.NOTA MAS AGUDA: %d.\nTOTAL NOTAS: %d.\n",note_min,note_max,note_max-note_min+1);
    
    fprintf(fp,"TONO MINIMO: %d. TONO MAXIMO: %d.\nTOTAL GENERADORES DE TONO: %d.\n",gear_min,gear_max,gear_max-gear_min+1);

    fprintf(fp,"RECORDAR QUE EL ACCESO A LA TABLA SE HACE CON UN OFFSET DE LA MENOR NOTA MIDI SELECCIONADA*/\n\n");
    
    fprintf(fp,"const uint8_t switchbox[%d] = { ",pasos);

    for(i=0;i<pasos;i++)
	{
	if(!(i % 9)) fprintf(fp,"\n");
	
	if(i == pasos - 1) fprintf(fp,"%d",switchbox[i]-note_min);
	else fprintf(fp,"%d,",switchbox[i]-note_min);
	}
    
    fprintf(fp,"};\n");
    
    fclose(fp);
    fp = NULL;
    return;
}


int main()
{

	double fmidi[128] = {0}; //DESDE C0 A G10
	double fsteps[128] = {0}; //Steps entre entradas de tabla, formato real
	int qsteps[128] = {0}; //Steps entre entradas de tabla, formato Q(ancho tabla, 16 de fraccional)
	int i,dummy;
	double fbase;
    
	printf("Longitud de palabra de entrada a tabla? (en bits) \n");
	scanf("%d",&tablewidth);
	printf("Frecuencia de muestreo (en Hertz)?\n");
	scanf("%d",&fs);
	printf("\n\n");
    
	fbase = fs/pow(2.0,(double)tablewidth);
	printf("La frecuencia base de onda es de: %lf Hz.\n",fbase);

	printf("Ingrese, en formato NOTA MIDI, la nota mas grave y la mas aguda del organo\nSeparados por enter\n");
	scanf("%d",&note_min);
	scanf("%d",&note_max);
	
	printf("Ingrese, en formato NOTA MIDI, la nota correspondiente al generador mas grave y mas agudo disponible\nSeparados por enter\n");
	scanf("%d",&gear_min);
	scanf("%d",&gear_max);
	
	int notas = note_max-note_min+1;
	int pasos = (notas)*9;
	
	int *switchbox = malloc(sizeof(int)*pasos);
	
	int j,gear_number;
	
	printf("OK\n");
	for(i=0;i<notas;i++)
	{
		printf("Note offset: %d Gear:",i);
		for(j=0;j<9;j++)
		{
			printf("%d ",j);
			gear_number = i + note_min + draw_shift[j]; //Nota del gear correspondiente.
			
			while(gear_number < gear_min || gear_number > gear_max) //REALIZAR FOLDBACK
			{
			if(gear_number < gear_min) gear_number +=12;
			else if(gear_number > gear_max) gear_number -=12;
			}
			switchbox[i*9+j] = gear_number;
		}
		printf("\n");
	}	
	
	switchbox_escribir_archivo(switchbox,note_max-note_min +1);


	calcular_tablamidi(fmidi,128);

	calcular_fsteps(fbase,fmidi,fsteps,128); //Calcula los saltos de tabla para generar cada una de las frecuencias de tabla
	calcular_qsteps(qsteps,fsteps,128);
	imprimir_resultados(fmidi,fsteps,qsteps,128);
	notecalc_escribir_archivo(gear_max,gear_min,qsteps);

}

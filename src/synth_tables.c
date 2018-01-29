/*
 * synth_tables.c
 *
 *  Created on: Jul 12, 2017
 *      Author: franco
 */

#include "includes.h"
#include "stm32f4xx.h"


/* Tabla de funcion senoidal. Vmax = 4095. Vmin = 0 */
/* Obtenida de la web:
 * http://www.daycounter.com/Calculators/Sine-Generator-Calculator.phtml
 *
 */

//ARCHIVO GENERADO AUTOMATICAMENTE POR LA UTILIDAD SineGen.
//UTN-frbb 2017 Tecnicas Digitales 3.
//ANCHO DE PALABRA DE TABLA: 12 bits

const int16_t wave_sine[TABLE_BUFF] = {

0x0000,0x0003,0x0006,0x0009,0x000C,0x000F,0x0012,0x0015,
0x0019,0x001C,0x001F,0x0022,0x0025,0x0028,0x002B,0x002F,
0x0032,0x0035,0x0038,0x003B,0x003E,0x0041,0x0045,0x0048,
0x004B,0x004E,0x0051,0x0054,0x0057,0x005B,0x005E,0x0061,
0x0064,0x0067,0x006A,0x006D,0x0070,0x0074,0x0077,0x007A,
0x007D,0x0080,0x0083,0x0086,0x008A,0x008D,0x0090,0x0093,
0x0096,0x0099,0x009C,0x009F,0x00A3,0x00A6,0x00A9,0x00AC,
0x00AF,0x00B2,0x00B5,0x00B9,0x00BC,0x00BF,0x00C2,0x00C5,
0x00C8,0x00CB,0x00CE,0x00D2,0x00D5,0x00D8,0x00DB,0x00DE,
0x00E1,0x00E4,0x00E7,0x00EA,0x00EE,0x00F1,0x00F4,0x00F7,
0x00FA,0x00FD,0x0100,0x0103,0x0107,0x010A,0x010D,0x0110,
0x0113,0x0116,0x0119,0x011C,0x011F,0x0123,0x0126,0x0129,
0x012C,0x012F,0x0132,0x0135,0x0138,0x013B,0x013E,0x0142,
0x0145,0x0148,0x014B,0x014E,0x0151,0x0154,0x0157,0x015A,
0x015D,0x0161,0x0164,0x0167,0x016A,0x016D,0x0170,0x0173,
0x0176,0x0179,0x017C,0x017F,0x0183,0x0186,0x0189,0x018C,
0x018F,0x0192,0x0195,0x0198,0x019B,0x019E,0x01A1,0x01A4,
0x01A7,0x01AB,0x01AE,0x01B1,0x01B4,0x01B7,0x01BA,0x01BD,
0x01C0,0x01C3,0x01C6,0x01C9,0x01CC,0x01CF,0x01D2,0x01D5,
0x01D8,0x01DC,0x01DF,0x01E2,0x01E5,0x01E8,0x01EB,0x01EE,
0x01F1,0x01F4,0x01F7,0x01FA,0x01FD,0x0200,0x0203,0x0206,
0x0209,0x020C,0x020F,0x0212,0x0215,0x0218,0x021B,0x021E,
0x0221,0x0224,0x0227,0x022B,0x022E,0x0231,0x0234,0x0237,
0x023A,0x023D,0x0240,0x0243,0x0246,0x0249,0x024C,0x024F,
0x0252,0x0255,0x0258,0x025B,0x025E,0x0261,0x0264,0x0267,
0x026A,0x026D,0x0270,0x0273,0x0276,0x0279,0x027C,0x027F,
0x0282,0x0285,0x0288,0x028B,0x028E,0x0290,0x0293,0x0296,
0x0299,0x029C,0x029F,0x02A2,0x02A5,0x02A8,0x02AB,0x02AE,
0x02B1,0x02B4,0x02B7,0x02BA,0x02BD,0x02C0,0x02C3,0x02C6,
0x02C9,0x02CC,0x02CF,0x02D2,0x02D4,0x02D7,0x02DA,0x02DD,
0x02E0,0x02E3,0x02E6,0x02E9,0x02EC,0x02EF,0x02F2,0x02F5,
0x02F8,0x02FA,0x02FD,0x0300,0x0303,0x0306,0x0309,0x030C,
0x030F,0x0312,0x0315,0x0318,0x031A,0x031D,0x0320,0x0323,
0x0326,0x0329,0x032C,0x032F,0x0332,0x0334,0x0337,0x033A,
0x033D,0x0340,0x0343,0x0346,0x0348,0x034B,0x034E,0x0351,
0x0354,0x0357,0x035A,0x035C,0x035F,0x0362,0x0365,0x0368,
0x036B,0x036E,0x0370,0x0373,0x0376,0x0379,0x037C,0x037F,
0x0381,0x0384,0x0387,0x038A,0x038D,0x038F,0x0392,0x0395,
0x0398,0x039B,0x039D,0x03A0,0x03A3,0x03A6,0x03A9,0x03AB,
0x03AE,0x03B1,0x03B4,0x03B7,0x03B9,0x03BC,0x03BF,0x03C2,
0x03C4,0x03C7,0x03CA,0x03CD,0x03CF,0x03D2,0x03D5,0x03D8,
0x03DB,0x03DD,0x03E0,0x03E3,0x03E5,0x03E8,0x03EB,0x03EE,
0x03F0,0x03F3,0x03F6,0x03F9,0x03FB,0x03FE,0x0401,0x0404,
0x0406,0x0409,0x040C,0x040E,0x0411,0x0414,0x0416,0x0419,
0x041C,0x041F,0x0421,0x0424,0x0427,0x0429,0x042C,0x042F,
0x0431,0x0434,0x0437,0x0439,0x043C,0x043F,0x0441,0x0444,
0x0447,0x0449,0x044C,0x044F,0x0451,0x0454,0x0456,0x0459,
0x045C,0x045E,0x0461,0x0464,0x0466,0x0469,0x046C,0x046E,
0x0471,0x0473,0x0476,0x0479,0x047B,0x047E,0x0480,0x0483,
0x0486,0x0488,0x048B,0x048D,0x0490,0x0492,0x0495,0x0498,
0x049A,0x049D,0x049F,0x04A2,0x04A4,0x04A7,0x04AA,0x04AC,
0x04AF,0x04B1,0x04B4,0x04B6,0x04B9,0x04BB,0x04BE,0x04C0,
0x04C3,0x04C5,0x04C8,0x04CA,0x04CD,0x04CF,0x04D2,0x04D4,
0x04D7,0x04D9,0x04DC,0x04DE,0x04E1,0x04E3,0x04E6,0x04E8,
0x04EB,0x04ED,0x04F0,0x04F2,0x04F5,0x04F7,0x04FA,0x04FC,
0x04FF,0x0501,0x0503,0x0506,0x0508,0x050B,0x050D,0x0510,
0x0512,0x0515,0x0517,0x0519,0x051C,0x051E,0x0521,0x0523,
0x0525,0x0528,0x052A,0x052D,0x052F,0x0531,0x0534,0x0536,
0x0539,0x053B,0x053D,0x0540,0x0542,0x0544,0x0547,0x0549,
0x054B,0x054E,0x0550,0x0552,0x0555,0x0557,0x0559,0x055C,
0x055E,0x0560,0x0563,0x0565,0x0567,0x056A,0x056C,0x056E,
0x0571,0x0573,0x0575,0x0578,0x057A,0x057C,0x057E,0x0581,
0x0583,0x0585,0x0588,0x058A,0x058C,0x058E,0x0591,0x0593,
0x0595,0x0597,0x059A,0x059C,0x059E,0x05A0,0x05A2,0x05A5,
0x05A7,0x05A9,0x05AB,0x05AE,0x05B0,0x05B2,0x05B4,0x05B6,
0x05B9,0x05BB,0x05BD,0x05BF,0x05C1,0x05C3,0x05C6,0x05C8,
0x05CA,0x05CC,0x05CE,0x05D0,0x05D3,0x05D5,0x05D7,0x05D9,
0x05DB,0x05DD,0x05DF,0x05E2,0x05E4,0x05E6,0x05E8,0x05EA,
0x05EC,0x05EE,0x05F0,0x05F3,0x05F5,0x05F7,0x05F9,0x05FB,
0x05FD,0x05FF,0x0601,0x0603,0x0605,0x0607,0x0609,0x060B,
0x060D,0x0610,0x0612,0x0614,0x0616,0x0618,0x061A,0x061C,
0x061E,0x0620,0x0622,0x0624,0x0626,0x0628,0x062A,0x062C,
0x062E,0x0630,0x0632,0x0634,0x0636,0x0638,0x063A,0x063C,
0x063E,0x0640,0x0642,0x0644,0x0645,0x0647,0x0649,0x064B,
0x064D,0x064F,0x0651,0x0653,0x0655,0x0657,0x0659,0x065B,
0x065D,0x065E,0x0660,0x0662,0x0664,0x0666,0x0668,0x066A,
0x066C,0x066E,0x066F,0x0671,0x0673,0x0675,0x0677,0x0679,
0x067A,0x067C,0x067E,0x0680,0x0682,0x0684,0x0685,0x0687,
0x0689,0x068B,0x068D,0x068E,0x0690,0x0692,0x0694,0x0696,
0x0697,0x0699,0x069B,0x069D,0x069E,0x06A0,0x06A2,0x06A4,
0x06A5,0x06A7,0x06A9,0x06AB,0x06AC,0x06AE,0x06B0,0x06B2,
0x06B3,0x06B5,0x06B7,0x06B8,0x06BA,0x06BC,0x06BE,0x06BF,
0x06C1,0x06C3,0x06C4,0x06C6,0x06C8,0x06C9,0x06CB,0x06CD,
0x06CE,0x06D0,0x06D1,0x06D3,0x06D5,0x06D6,0x06D8,0x06DA,
0x06DB,0x06DD,0x06DE,0x06E0,0x06E2,0x06E3,0x06E5,0x06E6,
0x06E8,0x06EA,0x06EB,0x06ED,0x06EE,0x06F0,0x06F1,0x06F3,
0x06F5,0x06F6,0x06F8,0x06F9,0x06FB,0x06FC,0x06FE,0x06FF,
0x0701,0x0702,0x0704,0x0705,0x0707,0x0708,0x070A,0x070B,
0x070D,0x070E,0x0710,0x0711,0x0713,0x0714,0x0716,0x0717,
0x0718,0x071A,0x071B,0x071D,0x071E,0x0720,0x0721,0x0722,
0x0724,0x0725,0x0727,0x0728,0x072A,0x072B,0x072C,0x072E,
0x072F,0x0730,0x0732,0x0733,0x0735,0x0736,0x0737,0x0739,
0x073A,0x073B,0x073D,0x073E,0x073F,0x0741,0x0742,0x0743,
0x0745,0x0746,0x0747,0x0748,0x074A,0x074B,0x074C,0x074E,
0x074F,0x0750,0x0751,0x0753,0x0754,0x0755,0x0756,0x0758,
0x0759,0x075A,0x075B,0x075D,0x075E,0x075F,0x0760,0x0761,
0x0763,0x0764,0x0765,0x0766,0x0767,0x0769,0x076A,0x076B,
0x076C,0x076D,0x076E,0x0770,0x0771,0x0772,0x0773,0x0774,
0x0775,0x0776,0x0778,0x0779,0x077A,0x077B,0x077C,0x077D,
0x077E,0x077F,0x0780,0x0781,0x0783,0x0784,0x0785,0x0786,
0x0787,0x0788,0x0789,0x078A,0x078B,0x078C,0x078D,0x078E,
0x078F,0x0790,0x0791,0x0792,0x0793,0x0794,0x0795,0x0796,
0x0797,0x0798,0x0799,0x079A,0x079B,0x079C,0x079D,0x079E,
0x079F,0x07A0,0x07A1,0x07A2,0x07A3,0x07A4,0x07A5,0x07A5,
0x07A6,0x07A7,0x07A8,0x07A9,0x07AA,0x07AB,0x07AC,0x07AD,
0x07AD,0x07AE,0x07AF,0x07B0,0x07B1,0x07B2,0x07B3,0x07B3,
0x07B4,0x07B5,0x07B6,0x07B7,0x07B8,0x07B8,0x07B9,0x07BA,
0x07BB,0x07BC,0x07BC,0x07BD,0x07BE,0x07BF,0x07C0,0x07C0,
0x07C1,0x07C2,0x07C3,0x07C3,0x07C4,0x07C5,0x07C6,0x07C6,
0x07C7,0x07C8,0x07C9,0x07C9,0x07CA,0x07CB,0x07CB,0x07CC,
0x07CD,0x07CD,0x07CE,0x07CF,0x07CF,0x07D0,0x07D1,0x07D1,
0x07D2,0x07D3,0x07D3,0x07D4,0x07D5,0x07D5,0x07D6,0x07D7,
0x07D7,0x07D8,0x07D8,0x07D9,0x07DA,0x07DA,0x07DB,0x07DB,
0x07DC,0x07DC,0x07DD,0x07DE,0x07DE,0x07DF,0x07DF,0x07E0,
0x07E0,0x07E1,0x07E1,0x07E2,0x07E2,0x07E3,0x07E3,0x07E4,
0x07E4,0x07E5,0x07E5,0x07E6,0x07E6,0x07E7,0x07E7,0x07E8,
0x07E8,0x07E9,0x07E9,0x07EA,0x07EA,0x07EB,0x07EB,0x07EB,
0x07EC,0x07EC,0x07ED,0x07ED,0x07EE,0x07EE,0x07EE,0x07EF,
0x07EF,0x07EF,0x07F0,0x07F0,0x07F1,0x07F1,0x07F1,0x07F2,
0x07F2,0x07F2,0x07F3,0x07F3,0x07F3,0x07F4,0x07F4,0x07F4,
0x07F5,0x07F5,0x07F5,0x07F6,0x07F6,0x07F6,0x07F6,0x07F7,
0x07F7,0x07F7,0x07F7,0x07F8,0x07F8,0x07F8,0x07F8,0x07F9,
0x07F9,0x07F9,0x07F9,0x07FA,0x07FA,0x07FA,0x07FA,0x07FA,
0x07FB,0x07FB,0x07FB,0x07FB,0x07FB,0x07FC,0x07FC,0x07FC,
0x07FC,0x07FC,0x07FC,0x07FC,0x07FD,0x07FD,0x07FD,0x07FD,
0x07FD,0x07FD,0x07FD,0x07FD,0x07FE,0x07FE,0x07FE,0x07FE,
0x07FE,0x07FE,0x07FE,0x07FE,0x07FE,0x07FE,0x07FE,0x07FE,
0x07FE,0x07FE,0x07FE,0x07FE,0x07FE,0x07FE,0x07FE,0x07FE,
0x07FE,0x07FE,0x07FE,0x07FE,0x07FE,0x07FE,0x07FE,0x07FE,
0x07FE,0x07FE,0x07FE,0x07FE,0x07FE,0x07FE,0x07FE,0x07FE,
0x07FE,0x07FE,0x07FE,0x07FE,0x07FE,0x07FD,0x07FD,0x07FD,
0x07FD,0x07FD,0x07FD,0x07FD,0x07FD,0x07FC,0x07FC,0x07FC,
0x07FC,0x07FC,0x07FC,0x07FC,0x07FB,0x07FB,0x07FB,0x07FB,
0x07FB,0x07FA,0x07FA,0x07FA,0x07FA,0x07FA,0x07F9,0x07F9,
0x07F9,0x07F9,0x07F8,0x07F8,0x07F8,0x07F8,0x07F7,0x07F7,
0x07F7,0x07F7,0x07F6,0x07F6,0x07F6,0x07F6,0x07F5,0x07F5,
0x07F5,0x07F4,0x07F4,0x07F4,0x07F3,0x07F3,0x07F3,0x07F2,
0x07F2,0x07F2,0x07F1,0x07F1,0x07F1,0x07F0,0x07F0,0x07EF,
0x07EF,0x07EF,0x07EE,0x07EE,0x07EE,0x07ED,0x07ED,0x07EC,
0x07EC,0x07EB,0x07EB,0x07EB,0x07EA,0x07EA,0x07E9,0x07E9,
0x07E8,0x07E8,0x07E7,0x07E7,0x07E6,0x07E6,0x07E6,0x07E5,
0x07E5,0x07E4,0x07E4,0x07E3,0x07E2,0x07E2,0x07E1,0x07E1,
0x07E0,0x07E0,0x07DF,0x07DF,0x07DE,0x07DE,0x07DD,0x07DD,
0x07DC,0x07DB,0x07DB,0x07DA,0x07DA,0x07D9,0x07D8,0x07D8,
0x07D7,0x07D7,0x07D6,0x07D5,0x07D5,0x07D4,0x07D3,0x07D3,
0x07D2,0x07D1,0x07D1,0x07D0,0x07CF,0x07CF,0x07CE,0x07CD,
0x07CD,0x07CC,0x07CB,0x07CB,0x07CA,0x07C9,0x07C9,0x07C8,
0x07C7,0x07C6,0x07C6,0x07C5,0x07C4,0x07C3,0x07C3,0x07C2,
0x07C1,0x07C0,0x07C0,0x07BF,0x07BE,0x07BD,0x07BD,0x07BC,
0x07BB,0x07BA,0x07B9,0x07B9,0x07B8,0x07B7,0x07B6,0x07B5,
0x07B4,0x07B4,0x07B3,0x07B2,0x07B1,0x07B0,0x07AF,0x07AE,
0x07AE,0x07AD,0x07AC,0x07AB,0x07AA,0x07A9,0x07A8,0x07A7,
0x07A6,0x07A5,0x07A5,0x07A4,0x07A3,0x07A2,0x07A1,0x07A0,
0x079F,0x079E,0x079D,0x079C,0x079B,0x079A,0x0799,0x0798,
0x0797,0x0796,0x0795,0x0794,0x0793,0x0792,0x0791,0x0790,
0x078F,0x078E,0x078D,0x078C,0x078B,0x078A,0x0789,0x0788,
0x0787,0x0786,0x0785,0x0784,0x0783,0x0782,0x0780,0x077F,
0x077E,0x077D,0x077C,0x077B,0x077A,0x0779,0x0778,0x0776,
0x0775,0x0774,0x0773,0x0772,0x0771,0x0770,0x076F,0x076D,
0x076C,0x076B,0x076A,0x0769,0x0767,0x0766,0x0765,0x0764,
0x0763,0x0762,0x0760,0x075F,0x075E,0x075D,0x075B,0x075A,
0x0759,0x0758,0x0756,0x0755,0x0754,0x0753,0x0751,0x0750,
0x074F,0x074E,0x074C,0x074B,0x074A,0x0749,0x0747,0x0746,
0x0745,0x0743,0x0742,0x0741,0x073F,0x073E,0x073D,0x073B,
0x073A,0x0739,0x0737,0x0736,0x0735,0x0733,0x0732,0x0731,
0x072F,0x072E,0x072C,0x072B,0x072A,0x0728,0x0727,0x0725,
0x0724,0x0723,0x0721,0x0720,0x071E,0x071D,0x071B,0x071A,
0x0719,0x0717,0x0716,0x0714,0x0713,0x0711,0x0710,0x070E,
0x070D,0x070B,0x070A,0x0708,0x0707,0x0705,0x0704,0x0702,
0x0701,0x06FF,0x06FE,0x06FC,0x06FB,0x06F9,0x06F8,0x06F6,
0x06F5,0x06F3,0x06F2,0x06F0,0x06EE,0x06ED,0x06EB,0x06EA,
0x06E8,0x06E7,0x06E5,0x06E3,0x06E2,0x06E0,0x06DF,0x06DD,
0x06DB,0x06DA,0x06D8,0x06D6,0x06D5,0x06D3,0x06D2,0x06D0,
0x06CE,0x06CD,0x06CB,0x06C9,0x06C8,0x06C6,0x06C4,0x06C3,
0x06C1,0x06BF,0x06BE,0x06BC,0x06BA,0x06B9,0x06B7,0x06B5,
0x06B3,0x06B2,0x06B0,0x06AE,0x06AD,0x06AB,0x06A9,0x06A7,
0x06A6,0x06A4,0x06A2,0x06A0,0x069F,0x069D,0x069B,0x0699,
0x0697,0x0696,0x0694,0x0692,0x0690,0x068F,0x068D,0x068B,
0x0689,0x0687,0x0686,0x0684,0x0682,0x0680,0x067E,0x067C,
0x067B,0x0679,0x0677,0x0675,0x0673,0x0671,0x066F,0x066E,
0x066C,0x066A,0x0668,0x0666,0x0664,0x0662,0x0660,0x065F,
0x065D,0x065B,0x0659,0x0657,0x0655,0x0653,0x0651,0x064F,
0x064D,0x064B,0x0649,0x0648,0x0646,0x0644,0x0642,0x0640,
0x063E,0x063C,0x063A,0x0638,0x0636,0x0634,0x0632,0x0630,
0x062E,0x062C,0x062A,0x0628,0x0626,0x0624,0x0622,0x0620,
0x061E,0x061C,0x061A,0x0618,0x0616,0x0614,0x0612,0x0610,
0x060E,0x060C,0x0609,0x0607,0x0605,0x0603,0x0601,0x05FF,
0x05FD,0x05FB,0x05F9,0x05F7,0x05F5,0x05F3,0x05F1,0x05EE,
0x05EC,0x05EA,0x05E8,0x05E6,0x05E4,0x05E2,0x05E0,0x05DD,
0x05DB,0x05D9,0x05D7,0x05D5,0x05D3,0x05D1,0x05CE,0x05CC,
0x05CA,0x05C8,0x05C6,0x05C4,0x05C1,0x05BF,0x05BD,0x05BB,
0x05B9,0x05B6,0x05B4,0x05B2,0x05B0,0x05AE,0x05AB,0x05A9,
0x05A7,0x05A5,0x05A3,0x05A0,0x059E,0x059C,0x059A,0x0597,
0x0595,0x0593,0x0591,0x058E,0x058C,0x058A,0x0588,0x0585,
0x0583,0x0581,0x057F,0x057C,0x057A,0x0578,0x0575,0x0573,
0x0571,0x056E,0x056C,0x056A,0x0568,0x0565,0x0563,0x0561,
0x055E,0x055C,0x055A,0x0557,0x0555,0x0553,0x0550,0x054E,
0x054C,0x0549,0x0547,0x0544,0x0542,0x0540,0x053D,0x053B,
0x0539,0x0536,0x0534,0x0531,0x052F,0x052D,0x052A,0x0528,
0x0526,0x0523,0x0521,0x051E,0x051C,0x0519,0x0517,0x0515,
0x0512,0x0510,0x050D,0x050B,0x0508,0x0506,0x0504,0x0501,
0x04FF,0x04FC,0x04FA,0x04F7,0x04F5,0x04F2,0x04F0,0x04ED,
0x04EB,0x04E8,0x04E6,0x04E4,0x04E1,0x04DF,0x04DC,0x04DA,
0x04D7,0x04D5,0x04D2,0x04D0,0x04CD,0x04CB,0x04C8,0x04C6,
0x04C3,0x04C0,0x04BE,0x04BB,0x04B9,0x04B6,0x04B4,0x04B1,
0x04AF,0x04AC,0x04AA,0x04A7,0x04A5,0x04A2,0x049F,0x049D,
0x049A,0x0498,0x0495,0x0493,0x0490,0x048D,0x048B,0x0488,
0x0486,0x0483,0x0480,0x047E,0x047B,0x0479,0x0476,0x0473,
0x0471,0x046E,0x046C,0x0469,0x0466,0x0464,0x0461,0x045F,
0x045C,0x0459,0x0457,0x0454,0x0451,0x044F,0x044C,0x0449,
0x0447,0x0444,0x0441,0x043F,0x043C,0x0439,0x0437,0x0434,
0x0431,0x042F,0x042C,0x0429,0x0427,0x0424,0x0421,0x041F,
0x041C,0x0419,0x0417,0x0414,0x0411,0x040E,0x040C,0x0409,
0x0406,0x0404,0x0401,0x03FE,0x03FB,0x03F9,0x03F6,0x03F3,
0x03F1,0x03EE,0x03EB,0x03E8,0x03E6,0x03E3,0x03E0,0x03DD,
0x03DB,0x03D8,0x03D5,0x03D2,0x03D0,0x03CD,0x03CA,0x03C7,
0x03C5,0x03C2,0x03BF,0x03BC,0x03B9,0x03B7,0x03B4,0x03B1,
0x03AE,0x03AC,0x03A9,0x03A6,0x03A3,0x03A0,0x039E,0x039B,
0x0398,0x0395,0x0392,0x0390,0x038D,0x038A,0x0387,0x0384,
0x0381,0x037F,0x037C,0x0379,0x0376,0x0373,0x0370,0x036E,
0x036B,0x0368,0x0365,0x0362,0x035F,0x035D,0x035A,0x0357,
0x0354,0x0351,0x034E,0x034B,0x0349,0x0346,0x0343,0x0340,
0x033D,0x033A,0x0337,0x0335,0x0332,0x032F,0x032C,0x0329,
0x0326,0x0323,0x0320,0x031D,0x031B,0x0318,0x0315,0x0312,
0x030F,0x030C,0x0309,0x0306,0x0303,0x0300,0x02FE,0x02FB,
0x02F8,0x02F5,0x02F2,0x02EF,0x02EC,0x02E9,0x02E6,0x02E3,
0x02E0,0x02DD,0x02DA,0x02D8,0x02D5,0x02D2,0x02CF,0x02CC,
0x02C9,0x02C6,0x02C3,0x02C0,0x02BD,0x02BA,0x02B7,0x02B4,
0x02B1,0x02AE,0x02AB,0x02A8,0x02A5,0x02A2,0x029F,0x029D,
0x029A,0x0297,0x0294,0x0291,0x028E,0x028B,0x0288,0x0285,
0x0282,0x027F,0x027C,0x0279,0x0276,0x0273,0x0270,0x026D,
0x026A,0x0267,0x0264,0x0261,0x025E,0x025B,0x0258,0x0255,
0x0252,0x024F,0x024C,0x0249,0x0246,0x0243,0x0240,0x023D,
0x023A,0x0237,0x0234,0x0231,0x022E,0x022B,0x0228,0x0225,
0x0222,0x021F,0x021C,0x0219,0x0215,0x0212,0x020F,0x020C,
0x0209,0x0206,0x0203,0x0200,0x01FD,0x01FA,0x01F7,0x01F4,
0x01F1,0x01EE,0x01EB,0x01E8,0x01E5,0x01E2,0x01DF,0x01DC,
0x01D9,0x01D6,0x01D3,0x01CF,0x01CC,0x01C9,0x01C6,0x01C3,
0x01C0,0x01BD,0x01BA,0x01B7,0x01B4,0x01B1,0x01AE,0x01AB,
0x01A8,0x01A5,0x01A1,0x019E,0x019B,0x0198,0x0195,0x0192,
0x018F,0x018C,0x0189,0x0186,0x0183,0x0180,0x017C,0x0179,
0x0176,0x0173,0x0170,0x016D,0x016A,0x0167,0x0164,0x0161,
0x015E,0x015B,0x0157,0x0154,0x0151,0x014E,0x014B,0x0148,
0x0145,0x0142,0x013F,0x013C,0x0138,0x0135,0x0132,0x012F,
0x012C,0x0129,0x0126,0x0123,0x0120,0x011C,0x0119,0x0116,
0x0113,0x0110,0x010D,0x010A,0x0107,0x0104,0x0100,0x00FD,
0x00FA,0x00F7,0x00F4,0x00F1,0x00EE,0x00EB,0x00E8,0x00E4,
0x00E1,0x00DE,0x00DB,0x00D8,0x00D5,0x00D2,0x00CF,0x00CB,
0x00C8,0x00C5,0x00C2,0x00BF,0x00BC,0x00B9,0x00B6,0x00B2,
0x00AF,0x00AC,0x00A9,0x00A6,0x00A3,0x00A0,0x009D,0x0099,
0x0096,0x0093,0x0090,0x008D,0x008A,0x0087,0x0083,0x0080,
0x007D,0x007A,0x0077,0x0074,0x0071,0x006E,0x006A,0x0067,
0x0064,0x0061,0x005E,0x005B,0x0058,0x0054,0x0051,0x004E,
0x004B,0x0048,0x0045,0x0042,0x003E,0x003B,0x0038,0x0035,
0x0032,0x002F,0x002C,0x0028,0x0025,0x0022,0x001F,0x001C,
0x0019,0x0016,0x0012,0x000F,0x000C,0x0009,0x0006,0x0003,
0x0000,0xFFFE,0xFFFA,0xFFF7,0xFFF4,0xFFF1,0xFFEE,0xFFEB,
0xFFE8,0xFFE4,0xFFE1,0xFFDE,0xFFDB,0xFFD8,0xFFD5,0xFFD2,
0xFFCE,0xFFCB,0xFFC8,0xFFC5,0xFFC2,0xFFBF,0xFFBC,0xFFB8,
0xFFB5,0xFFB2,0xFFAF,0xFFAC,0xFFA9,0xFFA6,0xFFA2,0xFF9F,
0xFF9C,0xFF99,0xFF96,0xFF93,0xFF90,0xFF8D,0xFF89,0xFF86,
0xFF83,0xFF80,0xFF7D,0xFF7A,0xFF77,0xFF73,0xFF70,0xFF6D,
0xFF6A,0xFF67,0xFF64,0xFF61,0xFF5E,0xFF5A,0xFF57,0xFF54,
0xFF51,0xFF4E,0xFF4B,0xFF48,0xFF45,0xFF41,0xFF3E,0xFF3B,
0xFF38,0xFF35,0xFF32,0xFF2F,0xFF2C,0xFF28,0xFF25,0xFF22,
0xFF1F,0xFF1C,0xFF19,0xFF16,0xFF13,0xFF0F,0xFF0C,0xFF09,
0xFF06,0xFF03,0xFF00,0xFEFD,0xFEFA,0xFEF7,0xFEF3,0xFEF0,
0xFEED,0xFEEA,0xFEE7,0xFEE4,0xFEE1,0xFEDE,0xFEDB,0xFED7,
0xFED4,0xFED1,0xFECE,0xFECB,0xFEC8,0xFEC5,0xFEC2,0xFEBF,
0xFEBB,0xFEB8,0xFEB5,0xFEB2,0xFEAF,0xFEAC,0xFEA9,0xFEA6,
0xFEA3,0xFEA0,0xFE9D,0xFE99,0xFE96,0xFE93,0xFE90,0xFE8D,
0xFE8A,0xFE87,0xFE84,0xFE81,0xFE7E,0xFE7B,0xFE77,0xFE74,
0xFE71,0xFE6E,0xFE6B,0xFE68,0xFE65,0xFE62,0xFE5F,0xFE5C,
0xFE59,0xFE56,0xFE53,0xFE4F,0xFE4C,0xFE49,0xFE46,0xFE43,
0xFE40,0xFE3D,0xFE3A,0xFE37,0xFE34,0xFE31,0xFE2E,0xFE2B,
0xFE28,0xFE25,0xFE22,0xFE1F,0xFE1B,0xFE18,0xFE15,0xFE12,
0xFE0F,0xFE0C,0xFE09,0xFE06,0xFE03,0xFE00,0xFDFD,0xFDFA,
0xFDF7,0xFDF4,0xFDF1,0xFDEE,0xFDEB,0xFDE8,0xFDE5,0xFDE2,
0xFDDF,0xFDDC,0xFDD9,0xFDD6,0xFDD3,0xFDD0,0xFDCD,0xFDCA,
0xFDC7,0xFDC4,0xFDC1,0xFDBD,0xFDBA,0xFDB7,0xFDB4,0xFDB1,
0xFDAE,0xFDAB,0xFDA8,0xFDA5,0xFDA2,0xFD9F,0xFD9C,0xFD99,
0xFD96,0xFD93,0xFD90,0xFD8D,0xFD8A,0xFD88,0xFD85,0xFD82,
0xFD7F,0xFD7C,0xFD79,0xFD76,0xFD73,0xFD70,0xFD6D,0xFD6A,
0xFD67,0xFD64,0xFD61,0xFD5E,0xFD5B,0xFD58,0xFD55,0xFD52,
0xFD4F,0xFD4C,0xFD49,0xFD46,0xFD43,0xFD40,0xFD3D,0xFD3A,
0xFD37,0xFD35,0xFD32,0xFD2F,0xFD2C,0xFD29,0xFD26,0xFD23,
0xFD20,0xFD1D,0xFD1A,0xFD17,0xFD14,0xFD11,0xFD0E,0xFD0B,
0xFD09,0xFD06,0xFD03,0xFD00,0xFCFD,0xFCFA,0xFCF7,0xFCF4,
0xFCF1,0xFCEE,0xFCEC,0xFCE9,0xFCE6,0xFCE3,0xFCE0,0xFCDD,
0xFCDA,0xFCD7,0xFCD4,0xFCD2,0xFCCF,0xFCCC,0xFCC9,0xFCC6,
0xFCC3,0xFCC0,0xFCBD,0xFCBB,0xFCB8,0xFCB5,0xFCB2,0xFCAF,
0xFCAC,0xFCA9,0xFCA7,0xFCA4,0xFCA1,0xFC9E,0xFC9B,0xFC98,
0xFC95,0xFC93,0xFC90,0xFC8D,0xFC8A,0xFC87,0xFC84,0xFC82,
0xFC7F,0xFC7C,0xFC79,0xFC76,0xFC74,0xFC71,0xFC6E,0xFC6B,
0xFC68,0xFC66,0xFC63,0xFC60,0xFC5D,0xFC5A,0xFC58,0xFC55,
0xFC52,0xFC4F,0xFC4C,0xFC4A,0xFC47,0xFC44,0xFC41,0xFC3E,
0xFC3C,0xFC39,0xFC36,0xFC33,0xFC31,0xFC2E,0xFC2B,0xFC28,
0xFC26,0xFC23,0xFC20,0xFC1D,0xFC1B,0xFC18,0xFC15,0xFC12,
0xFC10,0xFC0D,0xFC0A,0xFC08,0xFC05,0xFC02,0xFBFF,0xFBFD,
0xFBFA,0xFBF7,0xFBF4,0xFBF2,0xFBEF,0xFBEC,0xFBEA,0xFBE7,
0xFBE4,0xFBE2,0xFBDF,0xFBDC,0xFBDA,0xFBD7,0xFBD4,0xFBD1,
0xFBCF,0xFBCC,0xFBC9,0xFBC7,0xFBC4,0xFBC1,0xFBBF,0xFBBC,
0xFBBA,0xFBB7,0xFBB4,0xFBB2,0xFBAF,0xFBAC,0xFBAA,0xFBA7,
0xFBA4,0xFBA2,0xFB9F,0xFB9C,0xFB9A,0xFB97,0xFB95,0xFB92,
0xFB8F,0xFB8D,0xFB8A,0xFB88,0xFB85,0xFB82,0xFB80,0xFB7D,
0xFB7B,0xFB78,0xFB75,0xFB73,0xFB70,0xFB6E,0xFB6B,0xFB69,
0xFB66,0xFB63,0xFB61,0xFB5E,0xFB5C,0xFB59,0xFB57,0xFB54,
0xFB52,0xFB4F,0xFB4C,0xFB4A,0xFB47,0xFB45,0xFB42,0xFB40,
0xFB3D,0xFB3B,0xFB38,0xFB36,0xFB33,0xFB31,0xFB2E,0xFB2C,
0xFB29,0xFB27,0xFB24,0xFB22,0xFB1F,0xFB1D,0xFB1A,0xFB18,
0xFB15,0xFB13,0xFB10,0xFB0E,0xFB0B,0xFB09,0xFB06,0xFB04,
0xFB02,0xFAFF,0xFAFD,0xFAFA,0xFAF8,0xFAF5,0xFAF3,0xFAF0,
0xFAEE,0xFAEC,0xFAE9,0xFAE7,0xFAE4,0xFAE2,0xFAE0,0xFADD,
0xFADB,0xFAD8,0xFAD6,0xFAD4,0xFAD1,0xFACF,0xFACC,0xFACA,
0xFAC8,0xFAC5,0xFAC3,0xFAC0,0xFABE,0xFABC,0xFAB9,0xFAB7,
0xFAB5,0xFAB2,0xFAB0,0xFAAE,0xFAAB,0xFAA9,0xFAA7,0xFAA4,
0xFAA2,0xFAA0,0xFA9D,0xFA9B,0xFA99,0xFA96,0xFA94,0xFA92,
0xFA8F,0xFA8D,0xFA8B,0xFA89,0xFA86,0xFA84,0xFA82,0xFA7F,
0xFA7D,0xFA7B,0xFA79,0xFA76,0xFA74,0xFA72,0xFA70,0xFA6D,
0xFA6B,0xFA69,0xFA67,0xFA64,0xFA62,0xFA60,0xFA5E,0xFA5B,
0xFA59,0xFA57,0xFA55,0xFA53,0xFA50,0xFA4E,0xFA4C,0xFA4A,
0xFA48,0xFA45,0xFA43,0xFA41,0xFA3F,0xFA3D,0xFA3A,0xFA38,
0xFA36,0xFA34,0xFA32,0xFA30,0xFA2D,0xFA2B,0xFA29,0xFA27,
0xFA25,0xFA23,0xFA21,0xFA1E,0xFA1C,0xFA1A,0xFA18,0xFA16,
0xFA14,0xFA12,0xFA10,0xFA0E,0xFA0B,0xFA09,0xFA07,0xFA05,
0xFA03,0xFA01,0xF9FF,0xF9FD,0xF9FB,0xF9F9,0xF9F7,0xF9F5,
0xF9F3,0xF9F1,0xF9EF,0xF9EC,0xF9EA,0xF9E8,0xF9E6,0xF9E4,
0xF9E2,0xF9E0,0xF9DE,0xF9DC,0xF9DA,0xF9D8,0xF9D6,0xF9D4,
0xF9D2,0xF9D0,0xF9CE,0xF9CC,0xF9CA,0xF9C8,0xF9C6,0xF9C4,
0xF9C2,0xF9C0,0xF9BF,0xF9BD,0xF9BB,0xF9B9,0xF9B7,0xF9B5,
0xF9B3,0xF9B1,0xF9AF,0xF9AD,0xF9AB,0xF9A9,0xF9A7,0xF9A5,
0xF9A4,0xF9A2,0xF9A0,0xF99E,0xF99C,0xF99A,0xF998,0xF996,
0xF994,0xF993,0xF991,0xF98F,0xF98D,0xF98B,0xF989,0xF987,
0xF986,0xF984,0xF982,0xF980,0xF97E,0xF97C,0xF97B,0xF979,
0xF977,0xF975,0xF973,0xF972,0xF970,0xF96E,0xF96C,0xF96A,
0xF969,0xF967,0xF965,0xF963,0xF962,0xF960,0xF95E,0xF95C,
0xF95B,0xF959,0xF957,0xF955,0xF954,0xF952,0xF950,0xF94E,
0xF94D,0xF94B,0xF949,0xF948,0xF946,0xF944,0xF943,0xF941,
0xF93F,0xF93E,0xF93C,0xF93A,0xF939,0xF937,0xF935,0xF934,
0xF932,0xF930,0xF92F,0xF92D,0xF92B,0xF92A,0xF928,0xF926,
0xF925,0xF923,0xF922,0xF920,0xF91E,0xF91D,0xF91B,0xF91A,
0xF918,0xF916,0xF915,0xF913,0xF912,0xF910,0xF90F,0xF90D,
0xF90C,0xF90A,0xF908,0xF907,0xF905,0xF904,0xF902,0xF901,
0xF8FF,0xF8FE,0xF8FC,0xF8FB,0xF8F9,0xF8F8,0xF8F6,0xF8F5,
0xF8F3,0xF8F2,0xF8F0,0xF8EF,0xF8ED,0xF8EC,0xF8EB,0xF8E9,
0xF8E8,0xF8E6,0xF8E5,0xF8E3,0xF8E2,0xF8E0,0xF8DF,0xF8DE,
0xF8DC,0xF8DB,0xF8D9,0xF8D8,0xF8D7,0xF8D5,0xF8D4,0xF8D2,
0xF8D1,0xF8D0,0xF8CE,0xF8CD,0xF8CC,0xF8CA,0xF8C9,0xF8C7,
0xF8C6,0xF8C5,0xF8C3,0xF8C2,0xF8C1,0xF8BF,0xF8BE,0xF8BD,
0xF8BC,0xF8BA,0xF8B9,0xF8B8,0xF8B6,0xF8B5,0xF8B4,0xF8B2,
0xF8B1,0xF8B0,0xF8AF,0xF8AD,0xF8AC,0xF8AB,0xF8AA,0xF8A8,
0xF8A7,0xF8A6,0xF8A5,0xF8A3,0xF8A2,0xF8A1,0xF8A0,0xF89F,
0xF89D,0xF89C,0xF89B,0xF89A,0xF899,0xF897,0xF896,0xF895,
0xF894,0xF893,0xF892,0xF890,0xF88F,0xF88E,0xF88D,0xF88C,
0xF88B,0xF88A,0xF888,0xF887,0xF886,0xF885,0xF884,0xF883,
0xF882,0xF881,0xF880,0xF87F,0xF87E,0xF87C,0xF87B,0xF87A,
0xF879,0xF878,0xF877,0xF876,0xF875,0xF874,0xF873,0xF872,
0xF871,0xF870,0xF86F,0xF86E,0xF86D,0xF86C,0xF86B,0xF86A,
0xF869,0xF868,0xF867,0xF866,0xF865,0xF864,0xF863,0xF862,
0xF861,0xF860,0xF85F,0xF85E,0xF85D,0xF85C,0xF85C,0xF85B,
0xF85A,0xF859,0xF858,0xF857,0xF856,0xF855,0xF854,0xF853,
0xF853,0xF852,0xF851,0xF850,0xF84F,0xF84E,0xF84D,0xF84D,
0xF84C,0xF84B,0xF84A,0xF849,0xF848,0xF848,0xF847,0xF846,
0xF845,0xF844,0xF844,0xF843,0xF842,0xF841,0xF840,0xF840,
0xF83F,0xF83E,0xF83D,0xF83D,0xF83C,0xF83B,0xF83A,0xF83A,
0xF839,0xF838,0xF838,0xF837,0xF836,0xF835,0xF835,0xF834,
0xF833,0xF833,0xF832,0xF831,0xF831,0xF830,0xF82F,0xF82F,
0xF82E,0xF82D,0xF82D,0xF82C,0xF82B,0xF82B,0xF82A,0xF829,
0xF829,0xF828,0xF828,0xF827,0xF826,0xF826,0xF825,0xF825,
0xF824,0xF824,0xF823,0xF822,0xF822,0xF821,0xF821,0xF820,
0xF820,0xF81F,0xF81F,0xF81E,0xF81E,0xF81D,0xF81D,0xF81C,
0xF81C,0xF81B,0xF81B,0xF81A,0xF81A,0xF819,0xF819,0xF818,
0xF818,0xF817,0xF817,0xF816,0xF816,0xF815,0xF815,0xF815,
0xF814,0xF814,0xF813,0xF813,0xF812,0xF812,0xF812,0xF811,
0xF811,0xF811,0xF810,0xF810,0xF80F,0xF80F,0xF80F,0xF80E,
0xF80E,0xF80E,0xF80D,0xF80D,0xF80D,0xF80C,0xF80C,0xF80C,
0xF80B,0xF80B,0xF80B,0xF80A,0xF80A,0xF80A,0xF80A,0xF809,
0xF809,0xF809,0xF809,0xF808,0xF808,0xF808,0xF808,0xF807,
0xF807,0xF807,0xF807,0xF806,0xF806,0xF806,0xF806,0xF806,
0xF805,0xF805,0xF805,0xF805,0xF805,0xF804,0xF804,0xF804,
0xF804,0xF804,0xF804,0xF804,0xF803,0xF803,0xF803,0xF803,
0xF803,0xF803,0xF803,0xF803,0xF802,0xF802,0xF802,0xF802,
0xF802,0xF802,0xF802,0xF802,0xF802,0xF802,0xF802,0xF802,
0xF802,0xF802,0xF802,0xF802,0xF802,0xF802,0xF802,0xF802,
0xF802,0xF802,0xF802,0xF802,0xF802,0xF802,0xF802,0xF802,
0xF802,0xF802,0xF802,0xF802,0xF802,0xF802,0xF802,0xF802,
0xF802,0xF802,0xF802,0xF802,0xF802,0xF803,0xF803,0xF803,
0xF803,0xF803,0xF803,0xF803,0xF803,0xF804,0xF804,0xF804,
0xF804,0xF804,0xF804,0xF804,0xF805,0xF805,0xF805,0xF805,
0xF805,0xF806,0xF806,0xF806,0xF806,0xF806,0xF807,0xF807,
0xF807,0xF807,0xF807,0xF808,0xF808,0xF808,0xF808,0xF809,
0xF809,0xF809,0xF80A,0xF80A,0xF80A,0xF80A,0xF80B,0xF80B,
0xF80B,0xF80C,0xF80C,0xF80C,0xF80D,0xF80D,0xF80D,0xF80E,
0xF80E,0xF80E,0xF80F,0xF80F,0xF80F,0xF810,0xF810,0xF810,
0xF811,0xF811,0xF812,0xF812,0xF812,0xF813,0xF813,0xF814,
0xF814,0xF815,0xF815,0xF815,0xF816,0xF816,0xF817,0xF817,
0xF818,0xF818,0xF819,0xF819,0xF819,0xF81A,0xF81A,0xF81B,
0xF81B,0xF81C,0xF81C,0xF81D,0xF81D,0xF81E,0xF81F,0xF81F,
0xF820,0xF820,0xF821,0xF821,0xF822,0xF822,0xF823,0xF823,
0xF824,0xF825,0xF825,0xF826,0xF826,0xF827,0xF828,0xF828,
0xF829,0xF829,0xF82A,0xF82B,0xF82B,0xF82C,0xF82D,0xF82D,
0xF82E,0xF82E,0xF82F,0xF830,0xF830,0xF831,0xF832,0xF832,
0xF833,0xF834,0xF835,0xF835,0xF836,0xF837,0xF837,0xF838,
0xF839,0xF83A,0xF83A,0xF83B,0xF83C,0xF83D,0xF83D,0xF83E,
0xF83F,0xF840,0xF840,0xF841,0xF842,0xF843,0xF843,0xF844,
0xF845,0xF846,0xF847,0xF847,0xF848,0xF849,0xF84A,0xF84B,
0xF84C,0xF84C,0xF84D,0xF84E,0xF84F,0xF850,0xF851,0xF852,
0xF852,0xF853,0xF854,0xF855,0xF856,0xF857,0xF858,0xF859,
0xF85A,0xF85A,0xF85B,0xF85C,0xF85D,0xF85E,0xF85F,0xF860,
0xF861,0xF862,0xF863,0xF864,0xF865,0xF866,0xF867,0xF868,
0xF869,0xF86A,0xF86B,0xF86C,0xF86D,0xF86E,0xF86F,0xF870,
0xF871,0xF872,0xF873,0xF874,0xF875,0xF876,0xF877,0xF878,
0xF879,0xF87A,0xF87B,0xF87C,0xF87D,0xF87E,0xF880,0xF881,
0xF882,0xF883,0xF884,0xF885,0xF886,0xF887,0xF888,0xF889,
0xF88B,0xF88C,0xF88D,0xF88E,0xF88F,0xF890,0xF891,0xF893,
0xF894,0xF895,0xF896,0xF897,0xF898,0xF89A,0xF89B,0xF89C,
0xF89D,0xF89E,0xF8A0,0xF8A1,0xF8A2,0xF8A3,0xF8A5,0xF8A6,
0xF8A7,0xF8A8,0xF8A9,0xF8AB,0xF8AC,0xF8AD,0xF8AE,0xF8B0,
0xF8B1,0xF8B2,0xF8B4,0xF8B5,0xF8B6,0xF8B7,0xF8B9,0xF8BA,
0xF8BB,0xF8BD,0xF8BE,0xF8BF,0xF8C1,0xF8C2,0xF8C3,0xF8C5,
0xF8C6,0xF8C7,0xF8C9,0xF8CA,0xF8CB,0xF8CD,0xF8CE,0xF8CF,
0xF8D1,0xF8D2,0xF8D4,0xF8D5,0xF8D6,0xF8D8,0xF8D9,0xF8DB,
0xF8DC,0xF8DD,0xF8DF,0xF8E0,0xF8E2,0xF8E3,0xF8E4,0xF8E6,
0xF8E7,0xF8E9,0xF8EA,0xF8EC,0xF8ED,0xF8EF,0xF8F0,0xF8F2,
0xF8F3,0xF8F5,0xF8F6,0xF8F8,0xF8F9,0xF8FB,0xF8FC,0xF8FE,
0xF8FF,0xF901,0xF902,0xF904,0xF905,0xF907,0xF908,0xF90A,
0xF90B,0xF90D,0xF90E,0xF910,0xF912,0xF913,0xF915,0xF916,
0xF918,0xF919,0xF91B,0xF91D,0xF91E,0xF920,0xF921,0xF923,
0xF925,0xF926,0xF928,0xF929,0xF92B,0xF92D,0xF92E,0xF930,
0xF932,0xF933,0xF935,0xF937,0xF938,0xF93A,0xF93C,0xF93D,
0xF93F,0xF941,0xF942,0xF944,0xF946,0xF947,0xF949,0xF94B,
0xF94D,0xF94E,0xF950,0xF952,0xF953,0xF955,0xF957,0xF959,
0xF95A,0xF95C,0xF95E,0xF960,0xF961,0xF963,0xF965,0xF967,
0xF968,0xF96A,0xF96C,0xF96E,0xF970,0xF971,0xF973,0xF975,
0xF977,0xF979,0xF97A,0xF97C,0xF97E,0xF980,0xF982,0xF984,
0xF985,0xF987,0xF989,0xF98B,0xF98D,0xF98F,0xF990,0xF992,
0xF994,0xF996,0xF998,0xF99A,0xF99C,0xF99E,0xF99F,0xF9A1,
0xF9A3,0xF9A5,0xF9A7,0xF9A9,0xF9AB,0xF9AD,0xF9AF,0xF9B1,
0xF9B3,0xF9B5,0xF9B6,0xF9B8,0xF9BA,0xF9BC,0xF9BE,0xF9C0,
0xF9C2,0xF9C4,0xF9C6,0xF9C8,0xF9CA,0xF9CC,0xF9CE,0xF9D0,
0xF9D2,0xF9D4,0xF9D6,0xF9D8,0xF9DA,0xF9DC,0xF9DE,0xF9E0,
0xF9E2,0xF9E4,0xF9E6,0xF9E8,0xF9EA,0xF9EC,0xF9EE,0xF9F0,
0xF9F2,0xF9F4,0xF9F6,0xF9F8,0xF9FB,0xF9FD,0xF9FF,0xFA01,
0xFA03,0xFA05,0xFA07,0xFA09,0xFA0B,0xFA0D,0xFA0F,0xFA11,
0xFA14,0xFA16,0xFA18,0xFA1A,0xFA1C,0xFA1E,0xFA20,0xFA22,
0xFA25,0xFA27,0xFA29,0xFA2B,0xFA2D,0xFA2F,0xFA31,0xFA34,
0xFA36,0xFA38,0xFA3A,0xFA3C,0xFA3E,0xFA41,0xFA43,0xFA45,
0xFA47,0xFA49,0xFA4C,0xFA4E,0xFA50,0xFA52,0xFA54,0xFA57,
0xFA59,0xFA5B,0xFA5D,0xFA60,0xFA62,0xFA64,0xFA66,0xFA68,
0xFA6B,0xFA6D,0xFA6F,0xFA71,0xFA74,0xFA76,0xFA78,0xFA7B,
0xFA7D,0xFA7F,0xFA81,0xFA84,0xFA86,0xFA88,0xFA8B,0xFA8D,
0xFA8F,0xFA91,0xFA94,0xFA96,0xFA98,0xFA9B,0xFA9D,0xFA9F,
0xFAA2,0xFAA4,0xFAA6,0xFAA9,0xFAAB,0xFAAD,0xFAB0,0xFAB2,
0xFAB4,0xFAB7,0xFAB9,0xFABB,0xFABE,0xFAC0,0xFAC2,0xFAC5,
0xFAC7,0xFACA,0xFACC,0xFACE,0xFAD1,0xFAD3,0xFAD6,0xFAD8,
0xFADA,0xFADD,0xFADF,0xFAE2,0xFAE4,0xFAE6,0xFAE9,0xFAEB,
0xFAEE,0xFAF0,0xFAF3,0xFAF5,0xFAF7,0xFAFA,0xFAFC,0xFAFF,
0xFB01,0xFB04,0xFB06,0xFB09,0xFB0B,0xFB0D,0xFB10,0xFB12,
0xFB15,0xFB17,0xFB1A,0xFB1C,0xFB1F,0xFB21,0xFB24,0xFB26,
0xFB29,0xFB2B,0xFB2E,0xFB30,0xFB33,0xFB35,0xFB38,0xFB3A,
0xFB3D,0xFB3F,0xFB42,0xFB44,0xFB47,0xFB4A,0xFB4C,0xFB4F,
0xFB51,0xFB54,0xFB56,0xFB59,0xFB5B,0xFB5E,0xFB60,0xFB63,
0xFB66,0xFB68,0xFB6B,0xFB6D,0xFB70,0xFB72,0xFB75,0xFB78,
0xFB7A,0xFB7D,0xFB7F,0xFB82,0xFB85,0xFB87,0xFB8A,0xFB8C,
0xFB8F,0xFB92,0xFB94,0xFB97,0xFB99,0xFB9C,0xFB9F,0xFBA1,
0xFBA4,0xFBA7,0xFBA9,0xFBAC,0xFBAF,0xFBB1,0xFBB4,0xFBB6,
0xFBB9,0xFBBC,0xFBBE,0xFBC1,0xFBC4,0xFBC6,0xFBC9,0xFBCC,
0xFBCE,0xFBD1,0xFBD4,0xFBD6,0xFBD9,0xFBDC,0xFBDF,0xFBE1,
0xFBE4,0xFBE7,0xFBE9,0xFBEC,0xFBEF,0xFBF1,0xFBF4,0xFBF7,
0xFBFA,0xFBFC,0xFBFF,0xFC02,0xFC04,0xFC07,0xFC0A,0xFC0D,
0xFC0F,0xFC12,0xFC15,0xFC17,0xFC1A,0xFC1D,0xFC20,0xFC22,
0xFC25,0xFC28,0xFC2B,0xFC2D,0xFC30,0xFC33,0xFC36,0xFC39,
0xFC3B,0xFC3E,0xFC41,0xFC44,0xFC46,0xFC49,0xFC4C,0xFC4F,
0xFC52,0xFC54,0xFC57,0xFC5A,0xFC5D,0xFC5F,0xFC62,0xFC65,
0xFC68,0xFC6B,0xFC6D,0xFC70,0xFC73,0xFC76,0xFC79,0xFC7C,
0xFC7E,0xFC81,0xFC84,0xFC87,0xFC8A,0xFC8D,0xFC8F,0xFC92,
0xFC95,0xFC98,0xFC9B,0xFC9E,0xFCA0,0xFCA3,0xFCA6,0xFCA9,
0xFCAC,0xFCAF,0xFCB2,0xFCB4,0xFCB7,0xFCBA,0xFCBD,0xFCC0,
0xFCC3,0xFCC6,0xFCC8,0xFCCB,0xFCCE,0xFCD1,0xFCD4,0xFCD7,
0xFCDA,0xFCDD,0xFCE0,0xFCE2,0xFCE5,0xFCE8,0xFCEB,0xFCEE,
0xFCF1,0xFCF4,0xFCF7,0xFCFA,0xFCFC,0xFCFF,0xFD02,0xFD05,
0xFD08,0xFD0B,0xFD0E,0xFD11,0xFD14,0xFD17,0xFD1A,0xFD1D,
0xFD20,0xFD22,0xFD25,0xFD28,0xFD2B,0xFD2E,0xFD31,0xFD34,
0xFD37,0xFD3A,0xFD3D,0xFD40,0xFD43,0xFD46,0xFD49,0xFD4C,
0xFD4F,0xFD52,0xFD55,0xFD57,0xFD5A,0xFD5D,0xFD60,0xFD63,
0xFD66,0xFD69,0xFD6C,0xFD6F,0xFD72,0xFD75,0xFD78,0xFD7B,
0xFD7E,0xFD81,0xFD84,0xFD87,0xFD8A,0xFD8D,0xFD90,0xFD93,
0xFD96,0xFD99,0xFD9C,0xFD9F,0xFDA2,0xFDA5,0xFDA8,0xFDAB,
0xFDAE,0xFDB1,0xFDB4,0xFDB7,0xFDBA,0xFDBD,0xFDC0,0xFDC3,
0xFDC6,0xFDC9,0xFDCC,0xFDCF,0xFDD2,0xFDD5,0xFDD8,0xFDDB,
0xFDDE,0xFDE1,0xFDE4,0xFDE7,0xFDEA,0xFDED,0xFDF0,0xFDF3,
0xFDF6,0xFDFA,0xFDFD,0xFE00,0xFE03,0xFE06,0xFE09,0xFE0C,
0xFE0F,0xFE12,0xFE15,0xFE18,0xFE1B,0xFE1E,0xFE21,0xFE24,
0xFE27,0xFE2A,0xFE2D,0xFE30,0xFE33,0xFE37,0xFE3A,0xFE3D,
0xFE40,0xFE43,0xFE46,0xFE49,0xFE4C,0xFE4F,0xFE52,0xFE55,
0xFE58,0xFE5B,0xFE5E,0xFE61,0xFE65,0xFE68,0xFE6B,0xFE6E,
0xFE71,0xFE74,0xFE77,0xFE7A,0xFE7D,0xFE80,0xFE83,0xFE86,
0xFE8A,0xFE8D,0xFE90,0xFE93,0xFE96,0xFE99,0xFE9C,0xFE9F,
0xFEA2,0xFEA5,0xFEA8,0xFEAC,0xFEAF,0xFEB2,0xFEB5,0xFEB8,
0xFEBB,0xFEBE,0xFEC1,0xFEC4,0xFEC7,0xFECB,0xFECE,0xFED1,
0xFED4,0xFED7,0xFEDA,0xFEDD,0xFEE0,0xFEE3,0xFEE6,0xFEEA,
0xFEED,0xFEF0,0xFEF3,0xFEF6,0xFEF9,0xFEFC,0xFEFF,0xFF03,
0xFF06,0xFF09,0xFF0C,0xFF0F,0xFF12,0xFF15,0xFF18,0xFF1B,
0xFF1F,0xFF22,0xFF25,0xFF28,0xFF2B,0xFF2E,0xFF31,0xFF34,
0xFF38,0xFF3B,0xFF3E,0xFF41,0xFF44,0xFF47,0xFF4A,0xFF4D,
0xFF51,0xFF54,0xFF57,0xFF5A,0xFF5D,0xFF60,0xFF63,0xFF66,
0xFF6A,0xFF6D,0xFF70,0xFF73,0xFF76,0xFF79,0xFF7C,0xFF80,
0xFF83,0xFF86,0xFF89,0xFF8C,0xFF8F,0xFF92,0xFF95,0xFF99,
0xFF9C,0xFF9F,0xFFA2,0xFFA5,0xFFA8,0xFFAB,0xFFAF,0xFFB2,
0xFFB5,0xFFB8,0xFFBB,0xFFBE,0xFFC1,0xFFC5,0xFFC8,0xFFCB,
0xFFCE,0xFFD1,0xFFD4,0xFFD7,0xFFDB,0xFFDE,0xFFE1,0xFFE4,
0xFFE7,0xFFEA,0xFFED,0xFFF0,0xFFF4,0xFFF7,0xFFFA,0xFFFD};

/*ARCHIVO GENERADO AUTOMATICAMENTE POR LA UTILIDAD NOTECALC.
UTN-frbb 2017 Tecnicas Digitales 3.

-- TABLA DE SALTOS FRACCIONALES, ORDENADOS POR NUMERO DE NOTA MIDI --

DETALLES DE OPERACION:
FRECUENCA DE MUESTREO: 21000 Hz.
ANCHO DE PALABRA DE TABLA: 12 bits
RESOLUCION FRACCIONAL; 16 bits*/
//LA TABLA POSEE LOS SALTOS DE NOTAS ENTRE LA NOTA MIDI 36 Y LAS 114 INCLUSIVE, TOTAL: 79 TONOS

const uint32_t qstep[79] = {
											0x001012C2,0x0011076F,0x00120AA8,0x00131D4C,
0x00144045,0x0015748A,0x0016BB25,0x0018152B,0x001983C5,0x001B082B,0x001CA3AA,0x001E57A0, //40
0x00202583,0x00220EDE,0x00241551,0x00263A98,0x00288089,0x002AE915,0x002D764A,0x00302A56,
0x0033078A,0x00361056,0x00394753,0x003CAF40,0x00404B07,0x00441DBB,0x00482AA2,0x004C7531,
0x00510113,0x0055D22A,0x005AEC94,0x006054AD,0x00660F13,0x006C20AC,0x00728EA6,0x00795E81,
0x0080960D,0x00883B76,0x00905544,0x0098EA62,0x00A20226,0x00ABA454,0x00B5D928,0x00C0A95A,
0x00CC1E26,0x00D84158,0x00E51D4D,0x00F2BD02,0x01012C1B,0x011076EC,0x0120AA87,0x0131D4C3,
0x0144044B,0x015748A8,0x016BB250,0x018152B3,0x01983C4D,0x01B082B0,0x01CA3A9A,0x01E57A04,
0x02025835,0x0220EDD8,0x0241550E,0x0263A987,0x02880896,0x02AE914F,0x02D7649F,0x0302A567,
0x0330789A,0x03610560,0x03947534,0x03CAF407,0x0404B06A,0x0441DBB0,0x0482AA1D,0x04C7530D,
0x0510112C,0x055D229F,0x05AEC93E};


/*ARCHIVO GENERADO AUTOMATICAMENTE POR LA UTILIDAD SWITCHBOX.
UTN-frbb 2017 Tecnicas Digitales 3.

-- TABLA DE 9 CONTACTOS POR NOTA  --

LA NUMERACION ES INTERNA AL SISTEMA
PARA UNA CONVERSION A NOTA MIDI, SE DEBE SUMAR EL VALOR DE 36

DETALLES DE OPERACION:
NOTA MAS GRAVE 0.
NOTA MAS AGUDA: 51
TONO MINIMO 0 TONO MAXIMO 78*/

const uint8_t switchbox[459] = {
0,7,0,12,19,24,28,31,36,
1,8,1,13,20,25,29,32,37,
2,9,2,14,21,26,30,33,38,
3,10,3,15,22,27,31,34,39,
4,11,4,16,23,28,32,35,40,
5,12,5,17,24,29,33,36,41,
6,13,6,18,25,30,34,37,42,
7,14,7,19,26,31,35,38,43,
8,15,8,20,27,32,36,39,44,
9,16,9,21,28,33,37,40,45,
10,17,10,22,29,34,38,41,46,
11,18,11,23,30,35,39,42,47,
0,19,12,24,31,36,40,43,48,
1,20,13,25,32,37,41,44,49,
2,21,14,26,33,38,42,45,50,
3,22,15,27,34,39,43,46,51,
4,23,16,28,35,40,44,47,52,
5,24,17,29,36,41,45,48,53,
6,25,18,30,37,42,46,49,54,
7,26,19,31,38,43,47,50,55,
8,27,20,32,39,44,48,51,56,
9,28,21,33,40,45,49,52,57,
10,29,22,34,41,46,50,53,58,
11,30,23,35,42,47,51,54,59,
12,31,24,36,43,48,52,55,60,
13,32,25,37,44,49,53,56,61,
14,33,26,38,45,50,54,57,62,
15,34,27,39,46,51,55,58,63,
16,35,28,40,47,52,56,59,64,
17,36,29,41,48,53,57,60,65,
18,37,30,42,49,54,58,61,66,
19,38,31,43,50,55,59,62,67,
20,39,32,44,51,56,60,63,68,
21,40,33,45,52,57,61,64,69,
22,41,34,46,53,58,62,65,70,
23,42,35,47,54,59,63,66,71,
24,43,36,48,55,60,64,67,72,
25,44,37,49,56,61,65,68,73,
26,45,38,50,57,62,66,69,74,
27,46,39,51,58,63,67,70,75,
28,47,40,52,59,64,68,71,76,
29,48,41,53,60,65,69,72,77,
30,49,42,54,61,66,70,73,78,
31,50,43,55,62,67,71,74,67,
32,51,44,56,63,68,72,75,68,
33,52,45,57,64,69,73,76,69,
34,53,46,58,65,70,74,77,70,
35,54,47,59,66,71,75,78,71,
36,55,48,60,67,72,76,67,72,
37,56,49,61,68,73,77,68,73,
38,57,50,62,69,74,78,69,74};

uint16_t q4q8ampTable[79]; //Bus de amplitud en formato Q4.8 para cada tono

uint32_t q12q16phaseTable[79]; //Bus de fase en formato Q12.16 para cada tono

uint8_t MIDI_activeTable[16];

uint8_t synth_Drawbars[9];

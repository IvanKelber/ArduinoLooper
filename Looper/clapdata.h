// generated by Mozzi/extras/python/audio2huff.py 

#ifndef CLAP_H_
#define CLAP_H_

#if ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif 

#include <avr/pgmspace.h>
 

#define CLAP_SAMPLERATE 16384
#define CLAP_SAMPLE_BITS 8
int const __attribute__((section(".progmem.data"))) CLAP_HUFFMAN[349] = {
226,223,163,121,40,7,0,-10,4,0,16,0,11,31,0,-5,28,25,0,-25,22,10,4,0,66,0,55,4,0,54,0,50,10,4,0,49,0,48,4,0,
47,0,44,0,19,79,10,4,0,15,0,14,4,0,13,0,-19,67,0,-8,64,43,22,10,4,0,41,0,-39,4,0,-43,0,-44,10,4,0,-47,0,-51,
4,0,-52,0,-53,19,10,4,0,-56,0,-58,4,0,-59,0,-60,7,4,0,-61,0,-63,0,46,19,10,4,0,45,0,37,4,0,36,0,-36,7,4,0,
-42,0,-57,0,43,40,37,0,-4,34,22,10,4,0,42,0,34,4,0,32,0,29,10,4,0,24,0,-33,4,0,-35,0,-50,10,4,0,40,0,-18,4,
0,-22,0,-31,0,2,58,16,13,10,7,4,0,-32,0,27,0,-20,0,10,0,4,0,-2,40,7,4,0,9,0,8,0,5,31,28,13,0,-17,10,0,
25,7,4,0,-65,0,78,0,56,13,0,-16,10,4,0,52,0,39,4,0,38,0,20,0,6,0,0,121,88,85,58,31,25,16,10,4,0,-28,0,-30,
4,0,-40,0,-45,4,0,-27,0,-29,7,4,0,-34,0,-37,0,31,4,0,-12,0,-13,25,4,0,-15,0,-11,19,0,12,16,10,7,0,-46,4,0,74,
0,69,0,35,4,0,30,0,-38,25,13,0,-9,10,4,0,23,0,22,4,0,21,0,-21,10,7,4,0,-23,0,-24,0,-14,0,-7,0,1,31,0,-1,
28,13,0,3,10,0,-6,7,4,0,-26,0,33,0,18,13,10,7,0,17,4,0,28,0,26,0,7,0,-3
};
unsigned long const CLAP_SOUNDDATA_BITS = 14865L;
unsigned char const __attribute__((section(".progmem.data"))) CLAP_SOUNDDATA[] = {
86,231,226,112,251,243,77,10,153,158,17,226,30,114,144,30,72,161,127,62,90,36,222,228,73,28,25,64,76,138,243,146,5,6,99,168,240,98,0,179,
176,56,133,50,18,49,232,135,47,198,234,6,66,4,24,86,8,240,246,139,8,5,11,11,241,161,155,215,137,162,238,208,32,41,165,18,29,28,228,64,
69,19,160,158,118,207,63,121,249,5,136,20,100,43,144,175,190,136,116,71,175,107,159,233,201,34,24,216,96,126,251,208,225,134,31,166,98,131,146,117,
208,147,198,60,201,215,18,142,240,207,176,164,39,208,212,0,96,196,157,227,138,119,249,244,67,215,144,48,92,16,120,2,4,200,54,3,76,15,129,34,
226,12,201,204,7,12,41,146,24,236,48,26,7,8,1,128,128,0,12,75,31,5,59,128,64,61,227,143,133,26,20,40,89,127,41,147,128,92,48,64,
240,108,31,100,168,163,28,96,220,130,134,148,20,147,168,72,176,243,130,127,2,147,191,5,169,228,66,176,104,190,3,48,98,169,164,68,22,196,21,4,
33,189,161,187,247,13,2,151,50,19,16,52,73,79,43,5,5,28,134,29,125,128,65,240,237,131,134,32,64,193,193,65,64,121,227,130,12,192,224,251,
64,65,37,224,191,48,121,205,52,24,144,135,65,144,254,111,153,192,119,228,12,82,15,178,26,30,102,35,224,228,24,51,152,13,96,205,32,172,31,233,
96,96,178,44,145,36,243,33,0,48,63,36,62,203,74,152,252,18,17,220,20,17,32,171,217,48,72,54,248,143,156,225,38,96,48,16,160,35,158,126,
217,160,2,133,120,98,206,160,0,240,46,52,12,208,154,77,231,97,8,188,17,16,242,115,144,206,44,130,12,85,152,2,56,57,7,176,56,232,64,182,
45,136,26,12,237,128,39,136,0,211,148,88,79,156,40,130,148,99,128,234,36,56,60,12,61,7,96,115,203,74,28,29,147,55,182,96,30,9,226,5,
221,158,48,122,14,216,98,128,114,119,149,148,155,243,66,217,32,200,75,33,128,240,31,2,37,200,33,50,226,177,130,39,104,114,192,32,221,3,34,11,
184,81,4,52,176,48,222,200,23,70,60,229,227,188,176,167,128,228,52,8,26,37,34,96,233,23,247,3,20,127,29,129,10,243,138,157,136,53,1,66,
4,40,192,17,255,154,66,79,190,98,128,115,4,199,67,132,88,45,15,97,103,31,3,246,57,145,133,43,1,152,151,147,9,27,216,227,158,94,102,201,
204,98,72,129,142,240,4,133,133,130,52,63,15,206,161,205,11,166,152,38,63,237,140,118,126,32,174,99,220,68,201,32,80,72,113,227,229,197,177,238,
135,25,23,156,140,64,203,207,5,236,238,68,243,197,224,240,40,135,117,135,229,33,193,190,240,16,147,101,102,131,131,244,57,129,120,72,193,146,196,79,
21,99,161,51,69,57,251,144,2,196,47,196,131,144,248,160,0,191,232,60,216,249,143,202,202,77,50,60,116,64,232,8,43,209,100,33,115,236,49,124,
31,228,152,239,224,36,112,142,1,205,128,187,123,196,138,42,18,45,74,8,23,103,2,192,129,188,8,243,103,128,83,200,0,192,35,200,34,136,130,211,
197,99,36,147,44,47,25,17,133,126,103,240,132,2,60,28,28,36,46,9,226,19,60,129,165,96,230,64,142,128,206,5,198,0,204,115,193,209,110,44,
80,120,160,195,151,131,136,65,4,98,27,12,217,251,135,120,10,40,8,162,99,30,97,83,97,74,18,125,144,56,206,141,16,82,58,237,146,91,76,112,
32,217,0,72,68,7,83,49,137,143,72,120,31,66,164,196,88,100,50,128,226,17,135,18,36,168,255,24,72,158,144,119,81,39,58,241,51,220,8,44,
80,36,20,208,17,166,252,44,79,72,132,206,41,194,137,132,120,67,207,35,72,167,70,150,20,48,64,100,9,83,18,136,187,184,25,30,194,98,133,203,
0,141,38,40,129,0,126,83,0,36,144,49,224,141,8,251,77,52,28,91,14,53,18,36,134,74,83,233,143,5,156,227,208,18,225,62,9,225,200,234,
67,193,158,151,162,36,63,148,140,19,55,144,198,16,47,9,67,69,3,140,23,228,48,6,200,97,134,23,220,241,58,31,113,142,24,128,4,232,136,66,
5,16,7,166,36,135,224,153,19,114,57,200,120,6,198,156,17,63,8,140,46,76,180,77,47,189,48,11,136,31,38,132,14,65,61,159,158,254,112,30,
207,55,128,100,99,87,242,30,72,32,28,33,52,14,202,128,190,156,8,108,211,38,103,225,17,1,108,75,8,32,43,161,24,113,66,138,68,75,26,22,
192,167,51,224,64,5,51,167,169,159,245,237,36,20,94,122,120,97,19,28,134,100,79,201,24,42,76,24,222,27,11,135,154,24,76,127,161,132,16,255,
244,72,81,104,88,252,122,102,121,162,117,209,49,128,203,254,172,132,159,177,191,31,203,113,179,242,115,68,8,224,34,244,32,35,47,202,73,165,25,158,
168,133,73,13,195,80,192,130,185,247,78,33,144,152,100,158,88,166,134,0,19,243,76,112,79,194,25,106,127,191,24,110,27,74,2,67,205,60,98,98,
143,128,163,0,166,64,2,18,251,206,140,252,126,239,147,39,68,68,5,209,147,126,33,17,62,48,70,126,104,157,18,100,191,62,41,79,28,83,240,199,
32,63,254,48,83,140,144,216,167,152,189,112,127,249,157,211,215,55,168,130,18,104,36,154,1,231,239,167,209,6,72,12,95,255,148,100,252,240,213,166,
213,19,23,115,227,29,24,150,128,36,116,101,166,63,56,33,159,116,228,143,136,44,34,71,157,95,141,197,70,81,142,141,5,132,109,212,242,75,172,231,
200,92,72,222,12,122,238,126,121,253,207,9,255,17,9,225,65,18,24,184,210,110,180,165,195,198,163,249,112,155,20,147,199,215,45,219,8,104,241,75,
177,165,167,244,78,156,156,86,252,251,184,11,156,4,82,146,94,112,165,47,62,143,227,182,165,109,219,108,220,49,158,136,151,127,26,237,254,20,99,212,
101,197,115,73,220,197,112,245,16,163,81,209,231,157,127,138,39,57,82,168,242,226,74,34,84,150,170,90,210,183,112,175,16,67,126,182,142,213,197,112,
33,146,163,42,218,50,253,75,70,231,91,203,157,177,117,121,191,70,214,225,56,148,99,40,232,131,197,27,135,181,205,74,50,143,155,97,149,42,49,187,
100,123,227,30,85,40,223,242,142,150,151,227,191,206,29,171,193,148,171,138,213,91,75,110,29,46,75,105,71,181,173,173,250,253,163,30,118,170,81,230,
171,196,185,85,217,91,71,115,182,112,213,112,221,75,157,71,91,155,250,148,110,169,107,81,187,57,203,107,81,149,75,82,171,109,117,92,237,109,82,215,
81,231,107,174,226,85,118,181,85,81,150,187,85,117,85,170,236,90,182,163,106,92,236,90,58,219,156,170,234,234,230,230,218,187,101,90,170,170,234,173,
202,173,114,230,183,46,170,171,87,101,90,213,118,216,117,106,174,87,92,173,90,228,182,173,203,115,117,87,106,173,205,205,115,150,181,203,85,219,87,13,
213,85,87,93,85,165,170,218,91,156,213,106,229,118,184,118,165,70,93,150,213,110,85,85,165,170,170,183,46,183,43,149,107,117,85,217,85,170,181,202,
165,173,85,110,185,85,85,85,117,85,85,85,205,91,157,106,229,92,221,85,187,90,185,117,85,106,229,85,93,93,85,91,74,170,186,234,170,171,114,173,
206,170,173,202,171,181,106,60,171,178,181,85,85,213,90,174,92,173,117,107,149,93,93,110,170,229,85,185,87,85,110,85,117,90,185,115,85,85,110,107,
174,203,93,110,85,174,85,117,117,85,110,85,85,85,93,107,149,115,93,86,231,53,174,174,87,56,106,181,202,174,170,170,171,170,186,181,215,106,234,170,
173,202,234,170,173,202,229,170,173,215,58,170,171,170,170,174,170,170,170,170,171,170,185,173,87,92,185,90,170,170,170,170,170,235,171,93,114,170,234,170,
171,114,171,170,170,170,170,170,170,170,170,170,170,170,220,185,174,170,170,170,173,114,170,229,170,183,42,170,170,170,170,170,173,202,170,174,186,234,181,213,
206,170,170,170,170,170,186,170,181,202,170,183,43,170,170,170,170,170,128
};
#endif /* CLAP_H_ */

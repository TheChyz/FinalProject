/*
#include "compact_coeff.h"
#include "compact_R.h"

float Timing_Synchronization(int *Samples, int *Coeff) {
	float accReal = 0;
	float accImaginary = 0;
	int limit = 256;
	int i;
	if (Samples[129] == 0 && Samples[128] == 0) limit = 128;  //Can we assume 2 samples cannot be 0 right beside each other? ASK FABIO
	for (i = 0; i < limit; i++) {
		int samplesReal, coeffReal, samplesImaginary, coeffImaginary, coeff;
		int sample = Samples[i];
		if (sample != 0) {
			
			samplesReal = sample >> 16;   
			samplesImaginary = (sample << 16) >> 16; 
			coeff = Coeff[i];
			coeffReal = coeff >> 16; 
			coeffImaginary = (coeff << 16) >> 16;
			//because (a+ib)*(c+id) = (ac - db) + (ad + bc)i
			accReal += (samplesReal*coeffReal) - (samplesImaginary*coeffImaginary);
			accImaginary += (samplesReal*coeffImaginary) + (samplesImaginary*coeffReal);
		}	
		i++;
		sample = Samples[i];
		if (sample != 0) {
			
			samplesReal = sample >> 16;  
			samplesImaginary = (sample << 16) >> 16; 
			coeff = Coeff[i];
			coeffReal = coeff >> 16; 
			coeffImaginary = (coeff << 16) >> 16;
			//because (a+ib)*(c+id) = (ac - db) + (ad + bc)i
			accReal += (samplesReal*coeffReal) - (samplesImaginary*coeffImaginary);
			accImaginary += (samplesReal*coeffImaginary) + (samplesImaginary*coeffReal);
		}
}
	
	return (accReal*accReal) + (accImaginary*accImaginary);  //Real(acc)^2 + Imag(acc)^2	
	
}

		
int main() {
	float ans = Timing_Synchronization(R, coef);
	return 0;
}
*/

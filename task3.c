/*
#include "compact_coeff.h"
#include "compact_R.h"

const int DetThr=0x69000;
int mod_out;
int i,j,sample[256];

int Timing_Synchronization(int *Samples, int *Coeff) {
	int accReal = 0;
	int accImaginary = 0;
	int limit = 256;
	int i, coeff;	
	if (Samples[129] == 0 && Samples[128] == 0) limit = 128;  //Can we assume 2 samples cannot be 0 right beside each other? ASK FABIO
	for (i = 0; i < limit; i++) {
		int samplesReal, coeffReal, samplesImaginary, coeffImaginary;
		int sample = Samples[i];
		if (sample != 0) {
			
			samplesReal = sample >> 16;   
			samplesImaginary = (sample << 16) >> 16; 
			coeff = Coeff[i];
			coeffReal = coeff >> 16; 
			coeffImaginary = (coeff << 16) >> 16;
			//because (a+ib)*(c+id) = (ac - db) + (ad + bc)i
			accReal += ((samplesReal*coeffReal)>>16) - ((samplesImaginary*coeffImaginary) >> 16);
			accImaginary += ((samplesReal*coeffImaginary)>>16) + ((samplesImaginary*coeffReal) >> 16);
		}	
		i = i+1;
		sample = Samples[i];
		if (sample != 0) {
			
			samplesReal = sample >> 16;  
			samplesImaginary = (sample << 16) >> 16; 
			coeff = Coeff[i];
			coeffReal = coeff >> 16;  
			coeffImaginary = (coeff << 16) >> 16;
			//because (a+ib)*(c+id) = (ac - db) + (ad + bc)i
			accReal += ((samplesReal*coeffReal)>>16) - ((samplesImaginary*coeffImaginary) >> 16);
			accImaginary += ((samplesReal*coeffImaginary)>>16) + ((samplesImaginary*coeffReal) >> 16);
		}
}
	return (accReal*accReal) + (accImaginary*accImaginary);  //Real(acc)^2 + Imag(acc)^2		
}


int main()
{
	for(j=0;j<256;j++) sample[j]=0; // intialization, not necessary on a simulator, may be needed on a board
	// Parsing one by one all input samples. Every time we add a sample in slot 1,
	// we shift all samples of one unit and we remove the sample in slot 256, then we run the FIR again
	for(i=0;i<3394;i++) {
		for(j=255;j>0;j--) sample[j]=sample[j-1];sample[0]=R[i];
		mod_out=Timing_Synchronization(sample,coef);
		if (mod_out>=DetThr)
		{
			// BOOOOOOOONG!!!!! Synchronization Achieved!!!
			// Hint -> Place a Breakpoint here for performance measurements!
			return(i); //whenever the peak is found the system quits.
			// (in the simulation data the peak is located at i=715)
		};
	}
}
*/

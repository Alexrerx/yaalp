
#include "bcaudioheaders.h"

void example1()
{
	//create a sample sine wave.
	CAudioData* audio =  CAudioDataNew();
	errormsg msg = caudiodata_allocate(audio, 44100*4, 1, 44100); // 4 seconds of audio, mono.
	if (msg!=OK) puts(msg);
	
	double freq = 300;
	int i; for (i = 0; i < audio->length; i++)
	{
		audio->data[i] = 0.9 * sin(i * freq * 2.0 * PI / (double)audio->sampleRate);
	}
	
	msg = caudiodata_savewave(audio, "out.wav", 16);
	if (msg != OK) puts(msg);
	caudiodata_dispose( audio);
}


int main()
{
	printf("Hello");

	
	//~ char *tmp = malloc(128);
	//~ gets(stdout);
	//~ caudiodata_dispose( audio);
	//~ gets(stdout);
	return 0;
}


#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include "../include/lxaudio.h"
#include <AL/alc.h>

#define  SAMPLE_RATE  10000
#define  MAX_VALUE 32760

int lxaudio::open = 0;

void
lxaudio::Init(void)
{
 if (!lxaudio::open)
  {
   const char* defname = alcGetString (NULL, ALC_DEFAULT_DEVICE_SPECIFIER);
   ALCdevice* dev = alcOpenDevice (defname);
   ALCcontext* ctx = alcCreateContext (dev, NULL);
   alcMakeContextCurrent (ctx);
   printf ("open real\n");
  }
 lxaudio::open++;
 printf ("open %i\n", lxaudio::open);

 alGenBuffers (2, buf);
 alGenSources (1, &src);
}

void
lxaudio::End(void)
{
 alDeleteSources (1, &src);
 alDeleteBuffers (2, buf);

 printf ("close %i\n", lxaudio::open);
 lxaudio::open--;

 if (!lxaudio::open)
  {
   ALCcontext* ctx = alcGetCurrentContext ();
   ALCdevice* dev = alcGetContextsDevice (ctx);
   alcMakeContextCurrent (0);
   alcDestroyContext (ctx);
   alcCloseDevice (dev);
   printf ("close real\n");
  }
}

unsigned int
lxaudio::GetSampleRate(void)
{
 return SAMPLE_RATE;
}

unsigned int
lxaudio::GetMax(void)
{
 return MAX_VALUE;
}

void
lxaudio::BeepStart(float freq, float volume)
{
 ALint queue;
 alGetSourcei (src, AL_BUFFERS_QUEUED, &queue);

 if (queue == 0)
  {
   short* samples;

   size_t buf_size = SAMPLE_RATE;

   samples = new short[buf_size];

   if (samples == 0)
    {
     printf ("It seems there is no more heap memory. Sorry we cannot make a beep!");
    }
   for (unsigned i = 0; i < buf_size; i++)
    samples[i] = volume * 32760 * sin (2 * M_PI * i * freq / SAMPLE_RATE);

   alBufferData (buf[0], AL_FORMAT_MONO16, samples, buf_size, SAMPLE_RATE);
   delete[] samples;

   alSourceQueueBuffers (src, 1, buf);

   alSourcei (src, AL_LOOPING, AL_TRUE);

   alSourcePlay (src);
  }
}

void
lxaudio::BeepStop(void)
{
 ALint proc;
 ALint queue;
 ALuint buffer;

 alGetSourcei (src, AL_BUFFERS_QUEUED, &queue);
 if (queue)
  {
   alSourcei (src, AL_LOOPING, AL_FALSE);

   alSourceStop (src);

   alGetSourcei (src, AL_BUFFERS_PROCESSED, &proc);
   while (proc == 0)
    {
     alGetSourcei (src, AL_BUFFERS_PROCESSED, &proc);
    }

   alSourceUnqueueBuffers (src, 1, &buffer);
  }
}

int
lxaudio::SoundProcess(void)
{

 ALint status;
 ALint proc;
 ALuint buffer;

 if (!int_buf_size)return 1;


 alGetSourcei (src, AL_BUFFERS_PROCESSED, &proc);

 if (proc == 0) return 0;

 alSourceUnqueueBuffers (src, 1, &buffer);
 alBufferData (buffer, AL_FORMAT_MONO16, int_samples, int_buf_size, SAMPLE_RATE);
 alSourceQueueBuffers (src, 1, &buffer);

 alGetSourcei (src, AL_SOURCE_STATE, &status);

 if (status != AL_PLAYING)
  {
   alSourcePlay (src);
  }

 int_buf_size = 0;
 return 1;
}

void
lxaudio::SoundPlay(short * samples, size_t buf_size)
{
 ALint queue;
 alGetSourcei (src, AL_BUFFERS_QUEUED, &queue);
 if (queue == 0)
  {
   alBufferData (buf[0], AL_FORMAT_MONO16, samples, buf_size, SAMPLE_RATE);
   alBufferData (buf[1], AL_FORMAT_MONO16, samples, buf_size, SAMPLE_RATE);
   alSourceQueueBuffers (src, 2, buf);
   alSourcePlay (src);
  }
 else
  {
   int_samples = samples;
   int_buf_size = buf_size;
   SoundProcess ();
  }
}

/*
    Noise Sharpening dsp
    Copyright (C) 2010 Robert Y <Decatf@gmail.com>

    This program is free software; you can redistribute it and/or
    modify it under the terms of the GNU General Public License
    as published by the Free Software Foundation; either version 2
    of the License, or (at your option) any later version.
    
    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.
    
    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
*/

#include <gst/gst.h>
#include "delta.h"

gint8 *process8 (void* buf, gint n_samples, gint nch, gfloat gain)
{
  gdouble prevSample[nch];
  gint8 *samples = (gint8*)buf;

  for (int i = 0; i < nch; i++) 
      prevSample[i] = (gdouble)samples[i];

  for (int i = nch; i < n_samples; i+=nch) {
    
    for (int j = 0; j < nch; j++) {
			gdouble curr_sample = (gdouble)samples[i+j];
      gdouble result = curr_sample+(gain*(curr_sample-prevSample[j]));
      prevSample[j] = samples[i+j];
      samples[i+j] = (gint8) CLAMP(result, G_MININT8, G_MAXINT8);
    }
  }
  return samples;
}

guint8 *process8u (void* buf, gint n_samples, gint nch, gfloat gain)
{
  gdouble prevSample[nch];
  guint8 *samples = (guint8*)buf;

  for (int i = 0; i < nch; i++) 
      prevSample[i] = (gdouble)samples[i];

  for (int i = nch; i < n_samples; i+=nch) {
    
    for (int j = 0; j < nch; j++) {
			gdouble curr_sample = (gdouble)samples[i+j];
      gdouble result = curr_sample+(gain*(curr_sample-prevSample[j]));
      prevSample[j] = samples[i+j];
      samples[i+j] = (guint8) CLAMP(result, 0, G_MAXUINT8);
    }
  }
  return samples;
}

gint16 *process16 (void* buf, gint n_samples, gint nch, gfloat gain)
{
  gdouble prevSample[nch];
  gint16 *samples = (gint16*)buf;

  for (int i = 0; i < nch; i++) 
      prevSample[i] = (gdouble)samples[i];

  for (int i = nch; i < n_samples; i+=nch) {
    for (int j = 0; j < nch; j++) {
			gdouble curr_sample = (gdouble)samples[i+j];
      gdouble result = curr_sample+(gain*(curr_sample-prevSample[j]));
      prevSample[j] = samples[i+j];
      samples[i+j] = (gint16) CLAMP(result, G_MININT16, G_MAXINT16);
    }
  }
  return samples;
}

guint16 *process16u (void* buf, gint n_samples, gint nch, gfloat gain)
{
  gdouble prevSample[nch];
  guint16 *samples = (guint16*)buf;

  for (int i = 0; i < nch; i++) 
      prevSample[i] = (gdouble)samples[i];

  for (int i = nch; i < n_samples; i+=nch) {
    for (int j = 0; j < nch; j++) {
			gdouble curr_sample = (gdouble)samples[i+j];
      gdouble result = curr_sample+(gain*(curr_sample-prevSample[j]));
      prevSample[j] = samples[i+j];
      samples[i+j] = (guint16) CLAMP(result, 0, G_MAXUINT16);
    }
  }
  return samples;
}

gint32 *process32 (void* buf, gint n_samples, gint nch, gfloat gain)
{
  gdouble prevSample[nch];
  gint32 *samples = (gint32*)buf;

  for (int i = 0; i < nch; i++) 
      prevSample[i] = (gdouble)samples[i];

  for (int i = nch; i < n_samples; i+=nch) {
    for (int j = 0; j < nch; j++) {
			gdouble curr_sample = (gdouble)samples[i+j];
      gdouble result = curr_sample+(gain*(curr_sample-prevSample[j]));
      prevSample[j] = samples[i+j];
      samples[i+j] = (gint32) CLAMP(result, G_MININT32, G_MAXINT32);
    }
  }
  return samples;
}

guint32 *process32u (void* buf, gint n_samples, gint nch, gfloat gain)
{
  gdouble prevSample[nch];
  guint32 *samples = (guint32*)buf;

  for (int i = 0; i < nch; i++) 
      prevSample[i] = (gdouble)samples[i];

  for (int i = nch; i < n_samples; i+=nch) {
    for (int j = 0; j < nch; j++) {
			gdouble curr_sample = (gdouble)samples[i+j];
      gdouble result = curr_sample+(gain*(curr_sample-prevSample[j]));
      prevSample[j] = samples[i+j];
      samples[i+j] = (guint32) CLAMP(result, 0, G_MAXUINT32);
    }
  }
  return samples;
}

gint64 *process64 (void* buf, gint n_samples, gint nch, gfloat gain)
{
  gdouble prevSample[nch];
  gint64 *samples = (gint64*)buf;

  for (int i = 0; i < nch; i++) 
      prevSample[i] = (gdouble)samples[i];

  for (int i = nch; i < n_samples; i+=nch) {
    for (int j = 0; j < nch; j++) {
			gdouble curr_sample = (gdouble)samples[i+j];
      gdouble result = curr_sample+(gain*(curr_sample-prevSample[j]));
      prevSample[j] = samples[i+j];
      samples[i+j] = (gint64) CLAMP(result, G_MININT64, G_MAXINT64);
    }
  }
  return samples;
}

guint64 *process64u (void* buf, gint n_samples, gint nch, gfloat gain)
{
  gdouble prevSample[nch];
  guint64 *samples = (guint64*)buf;

  for (int i = 0; i < nch; i++) 
      prevSample[i] = (gdouble)samples[i];

  for (int i = nch; i < n_samples; i+=nch) {
    for (int j = 0; j < nch; j++) {
			gdouble curr_sample = (gdouble)samples[i+j];
      gdouble result = curr_sample+(gain*(curr_sample-prevSample[j]));
      prevSample[j] = samples[i+j];
      samples[i+j] = (guint64) CLAMP(result, 0, G_MAXUINT64);
    }
  }
  return samples;
}

gfloat *processf (void* buf, gint n_samples, gint nch, gfloat gain)
{
  gfloat prevSample[nch];
  gfloat *samples = (gfloat*)buf;

  for (int i = 0; i < nch; i++) 
      prevSample[i] = samples[i];

  for (int i = nch; i < n_samples; i+=nch) {
    gfloat result;
    for (int j = 0; j < nch; j++) {
      result = samples[i+j]+(gain*(samples[i+j]-prevSample[j]));
      prevSample[j] = samples[i+j];
      samples[i+j] = (gfloat) CLAMP(result, -G_MAXFLOAT, G_MAXFLOAT);
    }
  }
  return samples;
}

gdouble *processd (void* buf, gint n_samples, gint nch, gfloat gain)
{
  gdouble prevSample[nch];
  gdouble *samples = (gdouble*)buf;

  for (int i = 0; i < nch; i++) 
      prevSample[i] = samples[i];

  for (int i = nch; i < n_samples; i+=nch) {
    gdouble result;
    for (int j = 0; j < nch; j++) {
      result = samples[i+j]+(gain*(samples[i+j]-prevSample[j]));
      prevSample[j] = samples[i+j];
      samples[i+j] = (gdouble) CLAMP(result, -G_MAXDOUBLE, G_MAXDOUBLE);
    }
  }
  return samples;
}


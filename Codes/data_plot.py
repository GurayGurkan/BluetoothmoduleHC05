# -*- coding: utf-8 -*-
"""
Created on Thu Jan 04 17:57:54 2018

@author: g.gurkan
"""

import numpy as np
import matplotlib.pyplot as plt
import numpy.fft as f

#==============================================================================
# Accelerometer data for 10 Hz and 30 Hz freq. responses of a speaker. +z axis is the main displacement
#==============================================================================

data=np.loadtxt(u".\Dual.txt",dtype='int',delimiter=',')
plt.subplot(3,1,1)
plt.plot(data[:,[0,3]])
plt.grid(1)
plt.subplot(3,1,2)
plt.plot(data[:,[1,4]])
plt.grid(1)
plt.subplot(3,1,3)
#plt.plot(data[:,[2,5]],marker='.')


z1 = data[:,2]
z1 = z1-np.mean(z1)
z2 = data[:,5]
z2 = z2-np.mean(z2)
plt.plot(z1,marker='.')
plt.plot(z2,marker='.')
plt.grid(1)
plt.legend(('Dev0','Dev1'))
N=len(z1)
fs = 200.
fr =np.arange(N)*fs/N 

plt.figure(2)
plt.plot(fr,abs(f.fft(z1))/N)
plt.plot(fr,abs(f.fft(z2))/N)
plt.xlim(0,100)
plt.grid(1)
#data2=np.loadtxt(u"C:\ArduinoWorkspace\Bluetooth_and_Adxl345\DATA_30Hz.txt",dtype='int',delimiter=',')
#plt.figure(3)
#plt.plot(data2*0.0035)
#plt.grid(1)
#z = data2[:,2]
#z = z-np.mean(z)
#N=len(z)
#fs = 200.
#fr =np.arange(N)*fs/N 
#plt.figure(4)
#plt.plot(fr,abs(f.fft(z))/N)
#plt.xlim(0,50)
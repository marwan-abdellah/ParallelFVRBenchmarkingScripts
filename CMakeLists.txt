# *********************************************************************
# * Copyrights (c) Marwan Abdellah. All rights reserved.
# * This code is part of my Master's Thesis Project entitled "High
# * Performance Fourier Volume Rendering on Graphics Processing Units
# * (GPUs)" and submitted to the Systems & Biomedical Engineering
# * Department, Faculty of Engineering, Cairo University.
# * Please, don't use or distribute without authors' permission.

# * File        : Volume
# * Author(s)	: Marwan Abdellah <abdellah.marwan@gmail.com>
# * Created		: October 2014
# * Description	:
# * Note(s)		:
# *********************************************************************

# Minimum required CMake version 
cmake_minimum_required(VERSION 2.6)

# Fourier Volume Rendeing
PROJECT(ParallelFVR)

# Add CMake modules 
SET(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/CMake)

#########################################################
#! Find packages
#########################################################
# @FFTW
INCLUDE(Find_FFTW)

SET(FVR_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/Src)
INCLUDE_DIRECTORIES(${FVR_SOURCE_DIR}/)

SET(SOURCES
    ${FVR_SOURCE_DIR}/RandomNumberGeneration.cpp
    ${FVR_SOURCE_DIR}/FFTShift2D.cpp
    ${FVR_SOURCE_DIR}/FFTShift3D.cpp
    ${FVR_SOURCE_DIR}/FFTShift2D_InPlace.cpp
    ${FVR_SOURCE_DIR}/FFTShift2D_OutofPlace.cpp
    ${FVR_SOURCE_DIR}/FFTShift3D_InPlace.cpp
    ${FVR_SOURCE_DIR}/FFTShift3D_OutofPlace.cpp
    ${FVR_SOURCE_DIR}/FFTShiftProfiler.cpp
    ${FVR_SOURCE_DIR}/Profiler.cpp
    ${FVR_SOURCE_DIR}/FFT2D_Single.cpp
    ${FVR_SOURCE_DIR}/FFT2D_Double.cpp
    ${FVR_SOURCE_DIR}/FFT2D_InPlace.cpp
    ${FVR_SOURCE_DIR}/FFT2D_OutofPlace.cpp
    ${FVR_SOURCE_DIR}/FFT3D_Single.cpp
    ${FVR_SOURCE_DIR}/FFT3D_Double.cpp
    ${FVR_SOURCE_DIR}/FFT3D_InPlace.cpp
    ${FVR_SOURCE_DIR}/FFT3D_OutofPlace.cpp
    ${FVR_SOURCE_DIR}/FFTProfiler.cpp
    ${FVR_SOURCE_DIR}/FFTProfiler.cpp
)

SET(CMAKE_C_FLAGS " -fpermissive -fPIC -O3 -pthread -fopenmp -pipe -DLINUX -D_BOOL -DREQUIRE_IOSTREAM -Wno-deprecated -fno-gnu-keywords -w")
SET(CMAKE_CXX_FLAGS "${CMAKE_C_FLAGS}")
    
# Generate the executable considering. 
ADD_EXECUTABLE(profileFFTShift ${FVR_SOURCE_DIR}/runFFTShiftProfiler.cpp ${SOURCES})
ADD_EXECUTABLE(profileFFT ${FVR_SOURCE_DIR}/runFFTProfiler.cpp ${SOURCES})

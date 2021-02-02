// ==================================================================================
// Copyright (c) 2012 HiFi-LoFi
//
// This is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.
// ==================================================================================

#ifndef _FFTCONVOLVER_CONFIGURATION_H
#define _FFTCONVOLVER_CONFIGURATION_H


#if defined(__SSE__) || (defined(_M_IX86_FP) && _M_IX86_FP >= 2)
  #define FFTCONVOLVER_USE_SSE
#endif


#if defined (FFTCONVOLVER_USE_SSE)
  #include <xmmintrin.h>
#else
  #include <new>
#endif


namespace fftconvolver
{
namespace internal
{

#if defined(__GNUC__)
  #define FFTCONVOLVER_RESTRICT __restrict__
#else
  #define FFTCONVOLVER_RESTRICT
#endif


template<typename T>
T* AllocateBuffer(size_t size)
{
#if defined(FFTCONVOLVER_USE_SSE)
  return static_cast<T*>(_mm_malloc(size * sizeof(T), 16));
#else
  return new(std::nothrow) T[size];
#endif
}


template<typename T>
void DeallocateBuffer(T* ptr)
{
#if defined(FFTCONVOLVER_USE_SSE)
  _mm_free(ptr);
#else
  delete [] ptr;
#endif
}

} // End of namespace internal
  
inline bool SSEOptimized()
{
#if defined(FFTCONVOLVER_USE_SSE)
  return true;
#else
  return false;
#endif
}
  
} // End of namespace fftconvolver

#endif // Header guard

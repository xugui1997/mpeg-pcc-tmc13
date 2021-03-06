/* The copyright in this software is being made available under the BSD
 * Licence, included below.  This software may be subject to other third
 * party and contributor rights, including patent rights, and no such
 * rights are granted under this licence.
 *
 * Copyright (c) 2017-2018, ISO/IEC
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * * Redistributions of source code must retain the above copyright
 *   notice, this list of conditions and the following disclaimer.
 *
 * * Redistributions in binary form must reproduce the above copyright
 *   notice, this list of conditions and the following disclaimer in the
 *   documentation and/or other materials provided with the distribution.
 *
 * * Neither the name of the ISO/IEC nor the names of its contributors
 *   may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#pragma once

#include "PayloadBuffer.h"
#include "hls.h"

namespace pcc {

//============================================================================

PayloadBuffer write(const SequenceParameterSet& sps);
PayloadBuffer write(const GeometryParameterSet& gps);
PayloadBuffer write(const AttributeParameterSet& aps);
PayloadBuffer write(const TileInventory& inventory);

SequenceParameterSet parseSps(const PayloadBuffer& buf);
GeometryParameterSet parseGps(const PayloadBuffer& buf);
AttributeParameterSet parseAps(const PayloadBuffer& buf);
TileInventory parseTileInventory(const PayloadBuffer& buf);

//----------------------------------------------------------------------------

void write(
  const SequenceParameterSet& sps,
  const GeometryParameterSet& gps,
  const GeometryBrickHeader& gbh,
  PayloadBuffer* buf);

void write(
  const AttributeParameterSet& aps,
  const AttributeBrickHeader& abh,
  PayloadBuffer* buf);

GeometryBrickHeader parseGbh(
  const SequenceParameterSet& sps,
  const GeometryParameterSet& gps,
  const PayloadBuffer& buf,
  int* bytesRead);

AttributeBrickHeader parseAbh(
  const AttributeParameterSet& aps, const PayloadBuffer& buf, int* bytesRead);

/**
 * Parse @buf, decoding only the parameter set, slice, tile.
 * NB: the returned header is intentionally incomplete.
 */
GeometryBrickHeader parseGbhIds(const PayloadBuffer& buf);

/**
 * Parse @buf, decoding only the parameter set and slice ids.
 * NB: the returned header is intentionally incomplete.
 */
AttributeBrickHeader parseAbhIds(const PayloadBuffer& buf);

//----------------------------------------------------------------------------

//============================================================================

}  // namespace pcc
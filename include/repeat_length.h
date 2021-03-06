//
// Expansion Hunter
// Copyright (c) 2016 Illumina, Inc.
//
// Author: Egor Dolzhenko <edolzhenko@illumina.com>,
//         Mitch Bekritsky <mbekritsky@illumina.com>, Richard Shaw
// Concept: Michael Eberle <meberle@illumina.com>
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.
//

#ifndef INCLUDE_REPEAT_LENGTH_H_
#define INCLUDE_REPEAT_LENGTH_H_

#include <cstddef>

/*****************************************************************************/

void EstimateRepeatLen(const size_t num_irrs, const size_t read_len,
                       const double hap_depth, size_t& len_estimate,
                       size_t& lower_bound, size_t& upper_bound);

/*****************************************************************************/

#endif  // INCLUDE_REPEAT_LENGTH_H_

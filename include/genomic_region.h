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

#ifndef INCLUDE_GENOMIC_REGION_H_
#define INCLUDE_GENOMIC_REGION_H_

/*****************************************************************************/

#include <string>
#include <iostream>

/*****************************************************************************/

class Region {
 public:
  friend std::istream& operator>>(std::istream& istrm, Region& region);
  friend std::ostream& operator<<(std::ostream& ostrm, const Region& region);

  Region();
  Region(const std::string& chrom, size_t start, size_t end,
         const std::string& labelStr = std::string());
  Region(const std::string& rangeStr,
         const std::string& labelStr = std::string());

  bool is_set() const { return (chrom_ != "chr0"); }
  bool operator<(const Region& other_region) const;

  bool Overlaps(const Region& other_region) const;

  Region Extend(size_t extension_len) const;

  const std::string& chrom() const { return chrom_; }
  const size_t start() const { return start_; }
  const size_t end() const { return end_; }
  const std::string& label() const { return label_; }

  void set_start(size_t start) { start_ = start; }
  void set_end(size_t end) { end_ = end; }
  void set_label(const std::string& label) { label_ = label; }

  const std::string AsString() const;

 private:
  std::string chrom_;
  size_t start_;
  size_t end_;
  std::string label_;
};

/*****************************************************************************/

std::istream& operator>>(std::istream& istrm, Region& region);
std::ostream& operator<<(std::ostream& ostrm, const Region& region);

/*****************************************************************************/

#endif  // INCLUDE_GENOMIC_REGION_H_

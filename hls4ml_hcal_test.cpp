//
//    rfnoc-hls-neuralnet: Vivado HLS code for neural-net building blocks
//
//    Copyright (C) 2017 EJ Kreinar
//
//    This program is free software: you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation, either version 3 of the License, or
//    (at your option) any later version.
//
//    This program is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU General Public License for more details.
//
//    You should have received a copy of the GNU General Public License
//    along with this program.  If not, see <http://www.gnu.org/licenses/>.
//
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "parameters.h"
#include "ereg_v1.h"
#include "hls4ml_hcal.h"
#include "nnet_helpers.h"

int main(int argc, char **argv)
{

  //hls-fpga-machine-learning insert data
  data32_t  data_str[N_INPUTS*STREAMSIZE] = {0};

  data32_t res_str[N_OUTPUTS*STREAMSIZE] = {0};
  hls4ml_hcal(data_str, res_str);

  for(int j=0; j<std::min(10,STREAMSIZE); j++){
    for(int i=0; i<N_OUTPUTS; i++){
      std::cout << res_str[i] << " ";
    }
    std::cout<<std::endl;
  }
  std::cout << std::endl;
  
  return 0;
}

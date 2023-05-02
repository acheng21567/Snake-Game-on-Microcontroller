/*
 * image.h
 *
 *  Created on: Apr 30, 2023
 *      Author: Alvin Cheng & Sissi Liu
 */

#ifndef IMAGE_H_
#define IMAGE_H_

#include "stdint.h"

// Bitmap info for orange
#define ORANGE_SIZE          12
extern const uint8_t orangeBitmaps[];

extern const uint8_t headBitmapsRight[];
extern const uint8_t headBitmapsUp[];
extern const uint8_t headBitmapsLeft[];
extern const uint8_t headBitmapsDown[];

extern const uint8_t tailBitmapsRight[];
extern const uint8_t tailBitmapsUp[];
extern const uint8_t tailBitmapsLeft[];
extern const uint8_t tailBitmapsDown[];

#endif /* IMAGE_H_ */

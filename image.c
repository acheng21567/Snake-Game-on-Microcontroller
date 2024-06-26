/*
 * image.c
 *
 *  Created on: Apr 30, 2023
 *      Author: Alvin Cheng & Sissi Liu
 */

#include "image.h"

const uint8_t orangeBitmaps[] =
{
    0x1F, 0xC0, //    #######
    0x3F, 0xE0, //   #########
    0x7F, 0xF0, //  ###########
    0xFF, 0xF0, // ############
    0xFF, 0xF0, // ############
    0xFF, 0xF0, // ############
    0xFF, 0xF0, // ############
    0xFF, 0xF0, // ############
    0xFF, 0xF0, // ############
    0x7F, 0xE0, //  ##########
    0x3F, 0xC0, //   ########
    0x1F, 0x80, //    ######
};

const uint8_t headBitmapsRight[] =
{
     0xFF, 0xF8, 0x00, // #############
     0xFF, 0xFE, 0x00, // ###############
     0xFF, 0xFF, 0x00, // ################
     0xFF, 0xFF, 0x80, // #################
     0xFF, 0xFF, 0xE0, // ###################
     0xFF, 0xE7, 0xE0, // ###########  ######
     0xFF, 0xE7, 0xF0, // ###########  #######
     0xFF, 0xFF, 0xF8, // #####################
     0xFF, 0xFF, 0xF8, // #####################
     0xFF, 0xFF, 0xF8, // #####################
     0xFF, 0xFF, 0xF8, // #####################
     0xFF, 0xFF, 0xF8, // #####################
     0xFF, 0xFF, 0xF8, // #####################
     0xFF, 0xFF, 0xF8, // #####################
     0xFF, 0xE7, 0xF0, // ###########  #######
     0xFF, 0xE7, 0xE0, // ###########  ######
     0xFF, 0xFF, 0xE0, // ###################
     0xFF, 0xFF, 0x80, // #################
     0xFF, 0xFF, 0x00, // ################
     0xFF, 0xFE, 0x00, // ###############
     0xFF, 0xF8, 0x00, // #############
};

const uint8_t headBitmapsUp[] =
{
     0x01, 0xFC, 0x00, //        #######
     0x03, 0xFE, 0x00, //       #########
     0x0F, 0xFF, 0x80, //     #############
     0x0F, 0xFF, 0x80, //     #############
     0x1F, 0xFF, 0xC0, //    ###############
     0x3F, 0xFF, 0xE0, //   #################
     0x7F, 0xFF, 0xF0, //  ###################
     0x7F, 0xFF, 0xF0, //  ###################
     0xF9, 0xFC, 0xF8, // #####  #######  #####
     0xF9, 0xFC, 0xF8, // #####  #######  #####
     0xFF, 0xFF, 0xF8, // #####################
     0xFF, 0xFF, 0xF8, // #####################
     0xFF, 0xFF, 0xF8, // #####################
     0xFF, 0xFF, 0xF8, // #####################
     0xFF, 0xFF, 0xF8, // #####################
     0xFF, 0xFF, 0xF8, // #####################
     0xFF, 0xFF, 0xF8, // #####################
     0xFF, 0xFF, 0xF8, // #####################
     0xFF, 0xFF, 0xF8, // #####################
     0xFF, 0xFF, 0xF8, // #####################
     0xFF, 0xFF, 0xF8, // #####################
};

const uint8_t headBitmapsLeft[] =
{
    0x00, 0xFF, 0xF8, //         #############
    0x03, 0xFF, 0xF8, //       ###############
    0x07, 0xFF, 0xF8, //      ################
    0x0F, 0xFF, 0xF8, //     #################
    0x3F, 0xFF, 0xF8, //   ###################
    0x3F, 0x3F, 0xF8, //   ######  ###########
    0x7F, 0x3F, 0xF8, //  #######  ###########
    0xFF, 0xFF, 0xF8, // #####################
    0xFF, 0xFF, 0xF8, // #####################
    0xFF, 0xFF, 0xF8, // #####################
    0xFF, 0xFF, 0xF8, // #####################
    0xFF, 0xFF, 0xF8, // #####################
    0xFF, 0xFF, 0xF8, // #####################
    0xFF, 0xFF, 0xF8, // #####################
    0x7F, 0x3F, 0xF8, //  #######  ###########
    0x3F, 0x3F, 0xF8, //   ######  ###########
    0x3F, 0xFF, 0xF8, //   ###################
    0x0F, 0xFF, 0xF8, //     #################
    0x07, 0xFF, 0xF8, //      ################
    0x03, 0xFF, 0xF8, //       ###############
    0x00, 0xFF, 0xF8, //         #############
};

const uint8_t headBitmapsDown[] =
{
    0xFF, 0xFF, 0xF8, // #####################
    0xFF, 0xFF, 0xF8, // #####################
    0xFF, 0xFF, 0xF8, // #####################
    0xFF, 0xFF, 0xF8, // #####################
    0xFF, 0xFF, 0xF8, // #####################
    0xFF, 0xFF, 0xF8, // #####################
    0xFF, 0xFF, 0xF8, // #####################
    0xFF, 0xFF, 0xF8, // #####################
    0xFF, 0xFF, 0xF8, // #####################
    0xFF, 0xFF, 0xF8, // #####################
    0xFF, 0xFF, 0xF8, // #####################
    0xF9, 0xFC, 0xF8, // #####  #######  #####
    0xF9, 0xFC, 0xF8, // #####  #######  #####
    0x7F, 0xFF, 0xF0, //  ###################
    0x7F, 0xFF, 0xF0, //  ###################
    0x3F, 0xFF, 0xE0, //   #################
    0x1F, 0xFF, 0xC0, //    ###############
    0x0F, 0xFF, 0x80, //     #############
    0x0F, 0xFF, 0x80, //     #############
    0x03, 0xFE, 0x00, //       #########
    0x01, 0xFC, 0x00, //        #######
};

const uint8_t tailBitmapsRight[] = {
    0x00, 0x07, 0xF8, //              ########
    0x00, 0x0F, 0xF8, //             #########
    0x00, 0x1F, 0xF8, //            ##########
    0x00, 0x3F, 0xF8, //           ###########
    0x00, 0x7F, 0xF8, //          ############
    0x01, 0xFF, 0xF8, //        ##############
    0x03, 0xFF, 0xF8, //       ###############
    0x07, 0xFF, 0xF8, //      ################
    0x3F, 0xFF, 0xF8, //   ###################
    0xFF, 0xFF, 0xF8, // #####################
    0xFF, 0xFF, 0xF8, // #####################
    0xFF, 0xFF, 0xF8, // #####################
    0x3F, 0xFF, 0xF8, //   ###################
    0x07, 0xFF, 0xF8, //      ################
    0x03, 0xFF, 0xF8, //       ###############
    0x01, 0xFF, 0xF8, //        ##############
    0x00, 0x7F, 0xF8, //          ############
    0x00, 0x3F, 0xF8, //           ###########
    0x00, 0x1F, 0xF8, //            ##########
    0x00, 0x0F, 0xF8, //             #########
    0x00, 0x07, 0xF8, //              ########
};
const uint8_t tailBitmapsUp[] = {
    0xFF, 0xFF, 0xF8, // #####################
    0xFF, 0xFF, 0xF8, // #####################
    0xFF, 0xFF, 0xF8, // #####################
    0xFF, 0xFF, 0xF8, // #####################
    0xFF, 0xFF, 0xF8, // #####################
    0xFF, 0xFF, 0xF8, // #####################
    0xFF, 0xFF, 0xF8, // #####################
    0xFF, 0xFF, 0xF8, // #####################
    0x7F, 0xFF, 0xF0, //  ###################
    0x3F, 0xFF, 0xE0, //   #################
    0x1F, 0xFF, 0xC0, //    ###############
    0x0F, 0xFF, 0x80, //     #############
    0x07, 0xFF, 0x00, //      ###########
    0x07, 0xFF, 0x00, //      ###########
    0x03, 0xFE, 0x00, //       #########
    0x01, 0xFC, 0x00, //        #######
    0x00, 0xF8, 0x00, //         #####
    0x00, 0xF8, 0x00, //         #####
    0x00, 0xF8, 0x00, //         #####
    0x00, 0x70, 0x00, //          ###
     0x00, 0x70, 0x00, //          ###
};
const uint8_t tailBitmapsLeft[] = {
    0xFF, 0x00, 0x00, // ########
    0xFF, 0x80, 0x00, // #########
    0xFF, 0xC0, 0x00, // ##########
    0xFF, 0xE0, 0x00, // ###########
    0xFF, 0xF0, 0x00, // ############
    0xFF, 0xFC, 0x00, // ##############
    0xFF, 0xFE, 0x00, // ###############
    0xFF, 0xFF, 0x00, // ################
    0xFF, 0xFF, 0xE0, // ###################
    0xFF, 0xFF, 0xF8, // #####################
    0xFF, 0xFF, 0xF8, // #####################
    0xFF, 0xFF, 0xF8, // #####################
    0xFF, 0xFF, 0xE0, // ###################
    0xFF, 0xFF, 0x00, // ################
    0xFF, 0xFE, 0x00, // ###############
    0xFF, 0xFC, 0x00, // ##############
    0xFF, 0xF0, 0x00, // ############
    0xFF, 0xE0, 0x00, // ###########
    0xFF, 0xC0, 0x00, // ##########
    0xFF, 0x80, 0x00, // #########
0xFF, 0x00, 0x00, // ########
};
const uint8_t tailBitmapsDown[] = {
    0x00, 0x70, 0x00, //          ###
    0x00, 0x70, 0x00, //          ###
    0x00, 0xF8, 0x00, //         #####
    0x00, 0xF8, 0x00, //         #####
    0x00, 0xF8, 0x00, //         #####
    0x01, 0xFC, 0x00, //        #######
    0x03, 0xFE, 0x00, //       #########
    0x07, 0xFF, 0x00, //      ###########
    0x07, 0xFF, 0x00, //      ###########
    0x0F, 0xFF, 0x80, //     #############
    0x1F, 0xFF, 0xC0, //    ###############
    0x3F, 0xFF, 0xE0, //   #################
    0x7F, 0xFF, 0xF0, //  ###################
    0xFF, 0xFF, 0xF8, // #####################
    0xFF, 0xFF, 0xF8, // #####################
    0xFF, 0xFF, 0xF8, // #####################
    0xFF, 0xFF, 0xF8, // #####################
    0xFF, 0xFF, 0xF8, // #####################
    0xFF, 0xFF, 0xF8, // #####################
    0xFF, 0xFF, 0xF8, // #####################
0xFF, 0xFF, 0xF8, // #####################
};

const uint8_t game_overBitmaps[] =
{
    0x00, 0x00, 0x03, 0xF8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //                       #######
    0x00, 0x00, 0x1F, 0xFC, 0x00, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //                    ###########               ###
    0x00, 0x00, 0x7C, 0x0C, 0x00, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //                  #####      ##              ####
    0x00, 0x01, 0xE0, 0x04, 0x00, 0x0D, 0x80, 0x00, 0x00, 0x00, 0x00, 0xC0, 0x00, 0x00, 0x3C, //                ####          #              ## ##                                       ##                        ####
    0x00, 0x03, 0x80, 0x00, 0x00, 0x1D, 0x80, 0x00, 0x00, 0x00, 0x01, 0xC0, 0x1F, 0xFF, 0xFC, //               ###                          ### ##                                      ###         ###################
    0x00, 0x07, 0x00, 0x00, 0x00, 0x19, 0x80, 0x00, 0x00, 0x00, 0x03, 0xC0, 0x1F, 0xFF, 0xF8, //              ###                           ##  ##                                     ####         ##################
    0x00, 0x1C, 0x00, 0x00, 0x00, 0x10, 0xC0, 0x00, 0x00, 0x30, 0x03, 0x40, 0x0F, 0x00, 0x00, //            ###                             #    ##                        ##          ## #          ####
    0x00, 0x38, 0x00, 0x00, 0x00, 0x30, 0xC0, 0x00, 0x00, 0x70, 0x06, 0x40, 0x0F, 0x00, 0x00, //           ###                             ##    ##                       ###         ##  #          ####
    0x00, 0x30, 0x00, 0x00, 0x00, 0x30, 0xC0, 0x00, 0x00, 0x70, 0x06, 0x60, 0x0F, 0x00, 0x00, //           ##                              ##    ##                       ###         ##  ##         ####
    0x00, 0x60, 0x00, 0x00, 0x00, 0x60, 0x60, 0x00, 0x00, 0xD0, 0x0C, 0x60, 0x0E, 0x00, 0x00, //          ##                              ##      ##                     ## #        ##   ##         ###
    0x00, 0xC0, 0x00, 0x00, 0x00, 0x60, 0x60, 0x00, 0x00, 0xD0, 0x0C, 0x60, 0x0E, 0x00, 0x00, //         ##                               ##      ##                     ## #        ##   ##         ###
    0x01, 0xC0, 0x00, 0x00, 0x00, 0x60, 0x30, 0x00, 0x01, 0x90, 0x18, 0x20, 0x0E, 0x00, 0x00, //        ###                               ##       ##                   ##  #       ##     #         ###
    0x03, 0x80, 0x00, 0x00, 0x00, 0x40, 0x30, 0x00, 0x01, 0x90, 0x18, 0x20, 0x0E, 0x00, 0x00, //       ###                                #        ##                   ##  #       ##     #         ###
    0x03, 0x00, 0x00, 0x00, 0x00, 0xC0, 0x30, 0x00, 0x03, 0x10, 0x18, 0x30, 0x0E, 0x00, 0x00, //       ##                                ##        ##                  ##   #       ##     ##        ###
    0x06, 0x00, 0x00, 0x00, 0x00, 0xC0, 0x10, 0x00, 0x03, 0x10, 0x30, 0x30, 0x0E, 0x00, 0x00, //      ##                                 ##         #                  ##   #      ##      ##        ###
    0x06, 0x00, 0x00, 0x00, 0x00, 0xC0, 0x18, 0x00, 0x06, 0x10, 0x30, 0x30, 0x0E, 0x00, 0x00, //      ##                                 ##         ##                ##    #      ##      ##        ###
    0x0C, 0x00, 0x00, 0x00, 0x00, 0xC0, 0x18, 0x00, 0x06, 0x10, 0x30, 0x30, 0x0E, 0x00, 0x00, //     ##                                  ##         ##                ##    #      ##      ##        ###
    0x0C, 0x00, 0x00, 0x00, 0x00, 0x80, 0x0C, 0x00, 0x06, 0x10, 0x60, 0x10, 0x0E, 0x00, 0x00, //     ##                                  #           ##               ##    #     ##        #        ###
    0x18, 0x00, 0x00, 0x00, 0x01, 0x80, 0x0C, 0x00, 0x0C, 0x10, 0x60, 0x10, 0x0E, 0x00, 0x00, //    ##                                  ##           ##              ##     #     ##        #        ###
    0x18, 0x00, 0x00, 0x00, 0x01, 0x80, 0x0C, 0x00, 0x0C, 0x10, 0x40, 0x18, 0x0E, 0x00, 0x00, //    ##                                  ##           ##              ##     #     #         ##       ###
    0x18, 0x00, 0x00, 0x00, 0x01, 0x00, 0x04, 0x00, 0x18, 0x10, 0xC0, 0x18, 0x0E, 0x00, 0x00, //    ##                                  #             #             ##      #    ##         ##       ###
    0x30, 0x00, 0x00, 0x00, 0x01, 0x00, 0x06, 0x00, 0x18, 0x10, 0xC0, 0x18, 0x0E, 0x00, 0x00, //   ##                                   #             ##            ##      #    ##         ##       ###
    0x30, 0x00, 0x00, 0x00, 0x03, 0x00, 0x06, 0x00, 0x10, 0x11, 0x80, 0x18, 0x0F, 0xFF, 0xFE, //   ##                                  ##             ##            #       #   ##          ##       ###################
    0x20, 0x00, 0x00, 0x00, 0x03, 0x00, 0x06, 0x00, 0x30, 0x11, 0x80, 0x08, 0x0F, 0xFF, 0xFC, //   #                                   ##             ##           ##       #   ##           #       ##################
    0x60, 0x00, 0x00, 0x00, 0x03, 0x00, 0x06, 0x00, 0x30, 0x11, 0x80, 0x08, 0x0F, 0xFF, 0xFC, //  ##                                   ##             ##           ##       #   ##           #       ##################
    0x60, 0x00, 0x00, 0x00, 0x02, 0x00, 0x02, 0x00, 0x30, 0x11, 0x00, 0x0C, 0x0F, 0x81, 0xFC, //  ##                                   #               #           ##       #   #            ##      #####      #######
    0x60, 0x00, 0x00, 0x00, 0x06, 0x00, 0x02, 0x00, 0x30, 0x11, 0x00, 0x0C, 0x0E, 0x00, 0x00, //  ##                                  ##               #           ##       #   #            ##      ###
    0x60, 0x00, 0x00, 0x00, 0x07, 0xFF, 0xFA, 0x00, 0x20, 0x11, 0x00, 0x0C, 0x0E, 0x00, 0x00, //  ##                                  ################ #           #        #   #            ##      ###
    0x60, 0x00, 0x00, 0x00, 0x07, 0xFF, 0xFE, 0x00, 0x60, 0x1B, 0x00, 0x0C, 0x0E, 0x00, 0x00, //  ##                                  ##################          ##        ## ##            ##      ###
    0x60, 0x00, 0x1F, 0xC0, 0x04, 0x00, 0x03, 0x00, 0x60, 0x1B, 0x00, 0x04, 0x0E, 0x00, 0x00, //  ##                #######           #                ##         ##        ## ##             #      ###
    0x60, 0x00, 0xFF, 0xE0, 0x0C, 0x00, 0x03, 0x00, 0x60, 0x1B, 0x00, 0x04, 0x0E, 0x00, 0x00, //  ##             ###########         ##                ##         ##        ## ##             #      ###
    0x60, 0x00, 0x00, 0x60, 0x0C, 0x00, 0x03, 0x00, 0x40, 0x1B, 0x00, 0x04, 0x0E, 0x00, 0x00, //  ##                      ##         ##                ##         #         ## ##             #      ###
    0x60, 0x00, 0x00, 0x60, 0x0C, 0x00, 0x03, 0x00, 0xC0, 0x1B, 0x00, 0x06, 0x0E, 0x00, 0x00, //  ##                      ##         ##                ##        ##         ## ##             ##     ###
    0x60, 0x00, 0x00, 0x60, 0x0C, 0x00, 0x03, 0x00, 0xC0, 0x1A, 0x00, 0x06, 0x0E, 0x00, 0x00, //  ##                      ##         ##                ##        ##         ## #              ##     ###
    0x60, 0x00, 0x00, 0x60, 0x0C, 0x00, 0x03, 0x00, 0xC0, 0x1A, 0x00, 0x06, 0x0E, 0x00, 0x00, //  ##                      ##         ##                ##        ##         ## #              ##     ###
    0x60, 0x00, 0x00, 0x60, 0x0C, 0x00, 0x03, 0x00, 0xC0, 0x1A, 0x00, 0x02, 0x0E, 0x00, 0x00, //  ##                      ##         ##                ##        ##         ## #               #     ###
    0x60, 0x00, 0x00, 0x60, 0x08, 0x00, 0x01, 0x00, 0xC0, 0x1E, 0x00, 0x02, 0x0E, 0x00, 0x00, //  ##                      ##         #                  #        ##         ####               #     ###
    0x20, 0x00, 0x00, 0xE0, 0x08, 0x00, 0x01, 0x00, 0x80, 0x1E, 0x00, 0x02, 0x0E, 0x00, 0x00, //   #                     ###         #                  #        #          ####               #     ###
    0x30, 0x00, 0x01, 0xE0, 0x18, 0x00, 0x01, 0x01, 0x80, 0x1E, 0x00, 0x03, 0x0E, 0x00, 0x00, //   ##                   ####        ##                  #       ##          ####               ##    ###
    0x38, 0x00, 0x01, 0xA0, 0x18, 0x00, 0x01, 0x01, 0x80, 0x1E, 0x00, 0x03, 0x0E, 0x00, 0x00, //   ###                  ## #        ##                  #       ##          ####               ##    ###
    0x18, 0x00, 0x03, 0xA0, 0x18, 0x00, 0x01, 0x01, 0x80, 0x1C, 0x00, 0x03, 0x0E, 0x00, 0x00, //    ##                 ### #        ##                  #       ##          ###                ##    ###
    0x0C, 0x00, 0x07, 0x20, 0x18, 0x00, 0x01, 0x81, 0x80, 0x1C, 0x00, 0x03, 0x0E, 0x00, 0x00, //     ##               ###  #        ##                  ##      ##          ###                ##    ###
    0x0E, 0x00, 0x0E, 0x20, 0x18, 0x00, 0x01, 0x81, 0x80, 0x1C, 0x00, 0x01, 0x0E, 0x00, 0x00, //     ###             ###   #        ##                  ##      ##          ###                 #    ###
    0x07, 0x00, 0x1C, 0x20, 0x10, 0x00, 0x01, 0x81, 0x80, 0x1C, 0x00, 0x01, 0x0E, 0x00, 0x00, //      ###           ###    #        #                   ##      ##          ###                 #    ###
    0x03, 0x80, 0x78, 0x00, 0x10, 0x00, 0x01, 0x81, 0x00, 0x1C, 0x00, 0x01, 0x8F, 0xFF, 0xFE, //       ###        ####              #                   ##      #           ###                 ##   ###################
    0x01, 0xFF, 0xE0, 0x00, 0x10, 0x00, 0x01, 0x81, 0x00, 0x0C, 0x00, 0x01, 0x8F, 0xFF, 0xFE, //        ############                #                   ##      #            ##                 ##   ###################
    0x00, 0x7F, 0x00, 0x00, 0x00, 0x00, 0x01, 0x80, 0x00, 0x08, 0x00, 0x01, 0x8F, 0xFF, 0xF8, //          #######                                       ##                   #                  ##   #################
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x80, 0x00, 0x00, 0x00, 0x01, 0x80, 0x0F, 0x00, //                                                        ##                                      ##           ####
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //                                                        ##
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0xC0, 0x00, //                                                                                                      #####
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3F, 0xFE, 0x00, //                                                                                                   #############
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3F, 0xFF, 0xC0, //                                                                                                   ################
    0x00, 0x3E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xFF, 0xFF, 0xF0, 0x03, 0xFE, 0x07, 0xE0, //           #####                                               ######################          #########      ######
    0x00, 0x7F, 0x80, 0x03, 0x00, 0x00, 0x00, 0x03, 0xFF, 0xFF, 0xF8, 0x03, 0xF0, 0x00, 0x70, //          ########             ##                              #######################         ######             ###
    0x00, 0xE1, 0xC0, 0x03, 0xC0, 0x00, 0x01, 0xC3, 0xFF, 0xFF, 0xF0, 0x03, 0xC0, 0x00, 0x38, //         ###    ###            ####                     ###    ######################          ####                ###
    0x00, 0xC0, 0xC0, 0x01, 0xC0, 0x00, 0x03, 0xC3, 0x80, 0x00, 0x00, 0x03, 0xC0, 0x00, 0x3C, //         ##      ##             ###                    ####    ###                             ####                ####
    0x01, 0x80, 0x60, 0x01, 0xC0, 0x00, 0x03, 0x83, 0x80, 0x00, 0x00, 0x03, 0xC0, 0x00, 0x1C, //        ##        ##            ###                    ###     ###                             ####                 ###
    0x03, 0x00, 0x70, 0x01, 0xC0, 0x00, 0x03, 0x83, 0x80, 0x00, 0x00, 0x03, 0xC0, 0x00, 0x0C, //       ##         ###           ###                    ###     ###                             ####                  ##
    0x07, 0x00, 0x30, 0x01, 0xC0, 0x00, 0x03, 0x83, 0x80, 0x00, 0x00, 0x03, 0xC0, 0x00, 0x0C, //      ###          ##           ###                    ###     ###                             ####                  ##
    0x06, 0x00, 0x18, 0x01, 0xC0, 0x00, 0x03, 0x03, 0x80, 0x00, 0x00, 0x03, 0xC0, 0x00, 0x0C, //      ##            ##          ###                    ##      ###                             ####                  ##
    0x0C, 0x00, 0x18, 0x01, 0xC0, 0x00, 0x03, 0x03, 0x80, 0x00, 0x00, 0x03, 0x80, 0x00, 0x0C, //     ##             ##          ###                    ##      ###                             ###                   ##
    0x0C, 0x00, 0x0C, 0x00, 0xC0, 0x00, 0x07, 0x03, 0x80, 0x00, 0x00, 0x03, 0x80, 0x00, 0x0C, //     ##              ##          ##                   ###      ###                             ###                   ##
    0x18, 0x00, 0x0E, 0x00, 0xC0, 0x00, 0x07, 0x03, 0x80, 0x00, 0x00, 0x03, 0x80, 0x00, 0x1C, //    ##               ###         ##                   ###      ###                             ###                  ###
    0x18, 0x00, 0x06, 0x00, 0xC0, 0x00, 0x07, 0x03, 0x80, 0x00, 0x00, 0x03, 0x80, 0x00, 0x18, //    ##                ##         ##                   ###      ###                             ###                  ##
    0x30, 0x00, 0x06, 0x00, 0xC0, 0x00, 0x0F, 0x03, 0x80, 0x00, 0x00, 0x03, 0x80, 0x00, 0x38, //   ##                 ##         ##                  ####      ###                             ###                 ###
    0x30, 0x00, 0x03, 0x00, 0xC0, 0x00, 0x0E, 0x03, 0x80, 0x00, 0x00, 0x03, 0x80, 0x00, 0x38, //   ##                  ##        ##                  ###       ###                             ###                 ###
    0x60, 0x00, 0x03, 0x00, 0xE0, 0x00, 0x0E, 0x03, 0x80, 0x00, 0x00, 0x03, 0x80, 0x00, 0x70, //  ##                   ##        ###                 ###       ###                             ###                ###
    0x60, 0x00, 0x03, 0x00, 0xE0, 0x00, 0x0E, 0x03, 0x00, 0x00, 0x00, 0x07, 0x80, 0x00, 0xF0, //  ##                   ##        ###                 ###       ##                             ####               ####
    0x60, 0x00, 0x01, 0x80, 0xE0, 0x00, 0x0C, 0x03, 0x00, 0x00, 0x00, 0x07, 0x80, 0x01, 0xE0, //  ##                    ##       ###                 ##        ##                             ####              ####
    0x40, 0x00, 0x01, 0x80, 0x60, 0x00, 0x0C, 0x03, 0x00, 0x00, 0x00, 0x07, 0x80, 0x03, 0xC0, //  #                     ##        ##                 ##        ##                             ####             ####
    0xC0, 0x00, 0x01, 0xC0, 0x70, 0x00, 0x1C, 0x03, 0x00, 0x00, 0x00, 0x07, 0x80, 0x07, 0x80, // ##                     ###       ###               ###        ##                             ####            ####
    0xC0, 0x00, 0x00, 0xC0, 0x70, 0x00, 0x1C, 0x03, 0x00, 0x00, 0x00, 0x03, 0x80, 0x1F, 0x00, // ##                      ##       ###               ###        ##                              ###          #####
    0xC0, 0x00, 0x00, 0xC0, 0x70, 0x00, 0x18, 0x03, 0x00, 0x00, 0x00, 0x03, 0x00, 0x3E, 0x00, // ##                      ##       ###               ##         ##                              ##          #####
    0x80, 0x00, 0x00, 0xC0, 0x60, 0x00, 0x18, 0x03, 0x00, 0x00, 0x00, 0x03, 0x00, 0x7C, 0x00, // #                       ##       ##                ##         ##                              ##         #####
    0x80, 0x00, 0x00, 0x40, 0x60, 0x00, 0x18, 0x03, 0x00, 0x00, 0x00, 0x03, 0x00, 0xF8, 0x00, // #                        #       ##                ##         ##                              ##        #####
    0x80, 0x00, 0x00, 0x60, 0x60, 0x00, 0x38, 0x03, 0x00, 0x00, 0x00, 0x03, 0x0F, 0xC0, 0x00, // #                        ##      ##               ###         ##                              ##    ######
    0x80, 0x00, 0x00, 0x60, 0x60, 0x00, 0x38, 0x03, 0x00, 0x00, 0x00, 0x07, 0xFF, 0x00, 0x00, // #                        ##      ##               ###         ##                             ###########
    0x80, 0x00, 0x00, 0x60, 0x60, 0x00, 0x38, 0x03, 0x00, 0x00, 0x00, 0x07, 0xE0, 0x00, 0x00, // #                        ##      ##               ###         ##                             ######
    0x80, 0x00, 0x00, 0x60, 0x60, 0x00, 0x30, 0x03, 0x00, 0x00, 0x00, 0x07, 0xF0, 0x00, 0x00, // #                        ##      ##               ##          ##                             #######
    0x80, 0x00, 0x00, 0x40, 0x60, 0x00, 0x70, 0x03, 0xFF, 0xFF, 0xFC, 0x07, 0x78, 0x00, 0x00, // #                        #       ##              ###          ########################       ### ####
    0x80, 0x00, 0x00, 0x40, 0x20, 0x00, 0x70, 0x03, 0xFF, 0xFF, 0xFF, 0x07, 0x38, 0x00, 0x00, // #                        #        #              ###          ##########################     ###  ###
    0x80, 0x00, 0x00, 0x40, 0x30, 0x00, 0x70, 0x03, 0xFF, 0xFF, 0xFF, 0x07, 0x1C, 0x00, 0x00, // #                        #        ##             ###          ##########################     ###   ###
    0x80, 0x00, 0x00, 0x40, 0x30, 0x00, 0x70, 0x03, 0x00, 0x00, 0x00, 0x07, 0x0E, 0x00, 0x00, // #                        #        ##             ###          ##                             ###    ###
    0x80, 0x00, 0x00, 0xC0, 0x30, 0x00, 0x70, 0x03, 0x00, 0x00, 0x00, 0x07, 0x0F, 0x00, 0x00, // #                       ##        ##             ###          ##                             ###    ####
    0x80, 0x00, 0x00, 0xC0, 0x38, 0x00, 0x60, 0x03, 0x00, 0x00, 0x00, 0x07, 0x07, 0x00, 0x00, // #                       ##        ###            ##           ##                             ###     ###
    0x80, 0x00, 0x00, 0xC0, 0x38, 0x00, 0xE0, 0x03, 0x00, 0x00, 0x00, 0x07, 0x03, 0x80, 0x00, // #                       ##        ###           ###           ##                             ###      ###
    0x80, 0x00, 0x00, 0xC0, 0x18, 0x00, 0xE0, 0x03, 0x00, 0x00, 0x00, 0x07, 0x03, 0xC0, 0x00, // #                       ##         ##           ###           ##                             ###      ####
    0x80, 0x00, 0x00, 0x80, 0x18, 0x00, 0xE0, 0x03, 0x00, 0x00, 0x00, 0x07, 0x01, 0xC0, 0x00, // #                       #          ##           ###           ##                             ###       ###
    0x80, 0x00, 0x00, 0x80, 0x1C, 0x01, 0xC0, 0x03, 0x00, 0x00, 0x00, 0x07, 0x81, 0xE0, 0x00, // #                       #          ###         ###            ##                             ####      ####
    0xC0, 0x00, 0x01, 0x80, 0x1C, 0x01, 0xC0, 0x03, 0x00, 0x00, 0x00, 0x07, 0x81, 0xF0, 0x00, // ##                     ##          ###         ###            ##                             ####      #####
    0xC0, 0x00, 0x01, 0x80, 0x0C, 0x03, 0x80, 0x03, 0x00, 0x00, 0x00, 0x07, 0x80, 0xF8, 0x00, // ##                     ##           ##        ###             ##                             ####       #####
    0xC0, 0x00, 0x01, 0x80, 0x0E, 0x03, 0x80, 0x03, 0x00, 0x00, 0x00, 0x03, 0x80, 0x78, 0x00, // ##                     ##           ###       ###             ##                              ###        ####
    0xC0, 0x00, 0x01, 0x00, 0x0E, 0x03, 0x80, 0x03, 0x00, 0x00, 0x00, 0x03, 0x80, 0x3C, 0x00, // ##                     #            ###       ###             ##                              ###         ####
    0xC0, 0x00, 0x03, 0x00, 0x0E, 0x03, 0x00, 0x03, 0x00, 0x00, 0x00, 0x03, 0x80, 0x1E, 0x00, // ##                    ##            ###       ##              ##                              ###          ####
    0x40, 0x00, 0x03, 0x00, 0x07, 0x07, 0x00, 0x03, 0x00, 0x00, 0x00, 0x03, 0x80, 0x1E, 0x00, //  #                    ##             ###     ###              ##                              ###          ####
    0x40, 0x00, 0x03, 0x00, 0x07, 0x07, 0x00, 0x03, 0x00, 0x00, 0x00, 0x03, 0x80, 0x0F, 0x00, //  #                    ##             ###     ###              ##                              ###           ####
    0x60, 0x00, 0x02, 0x00, 0x07, 0x07, 0x00, 0x03, 0x00, 0x00, 0x00, 0x03, 0x80, 0x07, 0x00, //  ##                   #              ###     ###              ##                              ###            ###
    0x60, 0x00, 0x06, 0x00, 0x07, 0x0E, 0x00, 0x03, 0x00, 0x00, 0x00, 0x03, 0x80, 0x07, 0x80, //  ##                  ##              ###    ###               ##                              ###            ####
    0x60, 0x00, 0x06, 0x00, 0x03, 0x0E, 0x00, 0x03, 0x00, 0x00, 0x00, 0x03, 0x80, 0x03, 0xC0, //  ##                  ##               ##    ###               ##                              ###             ####
    0x30, 0x00, 0x0C, 0x00, 0x03, 0x8E, 0x00, 0x03, 0x00, 0x00, 0x00, 0x03, 0x80, 0x03, 0xC0, //   ##                ##                ###   ###               ##                              ###             ####
    0x30, 0x00, 0x0C, 0x00, 0x03, 0x8C, 0x00, 0x03, 0x00, 0x00, 0x00, 0x03, 0x80, 0x01, 0xE0, //   ##                ##                ###   ##                ##                              ###              ####
    0x18, 0x00, 0x18, 0x00, 0x01, 0x9C, 0x00, 0x03, 0x00, 0x00, 0x00, 0x03, 0x80, 0x00, 0xF0, //    ##              ##                  ##  ###                ##                              ###               ####
    0x18, 0x00, 0x18, 0x00, 0x01, 0xD8, 0x00, 0x03, 0x00, 0x00, 0x00, 0x03, 0x80, 0x00, 0xF8, //    ##              ##                  ### ##                 ##                              ###               #####
    0x0C, 0x00, 0x30, 0x00, 0x01, 0xD8, 0x00, 0x03, 0x00, 0x00, 0x00, 0x03, 0x80, 0x00, 0x7C, //     ##            ##                   ### ##                 ##                              ###                #####
    0x0E, 0x00, 0x70, 0x00, 0x00, 0xF8, 0x00, 0x03, 0x8F, 0x00, 0x00, 0x03, 0x80, 0x00, 0x3C, //     ###          ###                    #####                 ###   ####                      ###                 ####
    0x07, 0x81, 0xE0, 0x00, 0x00, 0xF8, 0x00, 0x03, 0xFF, 0xFF, 0xFF, 0x83, 0x80, 0x00, 0x1E, //      ####      ####                     #####                 ###########################     ###                  ####
    0x01, 0xFF, 0x80, 0x00, 0x00, 0xF0, 0x00, 0x03, 0xFF, 0xF9, 0xFF, 0x83, 0x80, 0x00, 0x1E, //        ##########                       ####                  ###############  ##########     ###                  ####
    0x00, 0x7E, 0x00, 0x00, 0x00, 0x70, 0x00, 0x01, 0x00, 0x00, 0x00, 0x03, 0x80, 0x00, 0x0C, //          ######                          ###                   #                              ###                   ##
};


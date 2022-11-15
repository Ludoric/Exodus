/*****************************************************************/
/*                                                               */
/*   CASIO fx-9860G SDK Library                                  */
/*                                                               */
/*   File name : [ProjectName].c                                 */
/*                                                               */
/*   Copyright (c) 2006 CASIO COMPUTER CO., LTD.                 */
/*                                                               */
/*****************************************************************/
#include "fxlib.h"
#include "timer.h"





//****************************************************************************
//  AddIn_main (Sample program main function)
//
//  param   :   isAppli   : 1 = This application is launched by MAIN MENU.
//                        : 0 = This application is launched by a strip in eACT application.
//
//              OptionNum : Strip number (0~3)
//                         (This parameter is only used when isAppli parameter is 0.)
//
//  retval  :   1 = No error / 0 = Error
//
//****************************************************************************
const unsigned int LEVEL_0_1[] = { 0xffff, 0xffff, 0xc000, 0xc000, 0xc000, 0xf000, 0xc000, 0xc0c0, 0xc000, 0xf000, 0xfc00, 0xfc00, 0xfc00, 0xc000, 0xc000, 0xc000, 0xc3f0, 0xc000, 0xc000, 0xc000, 0xc030, 0xc030, 0xc030, 0xc030, 0xc030, 0xf000, 0xf000, 0xf3c0, 0xf000, 0xc000, 0xc000, 0xffff };
const unsigned int LEVEL_0_2[] = { 0xffff, 0xc000, 0xc000, 0xc100, 0xc200, 0xc310, 0xc110, 0xc110, 0xc110, 0xc010, 0xc110, 0xc500, 0xc000, 0xc000, 0xc000, 0xc080, 0xc280, 0xc000, 0xc800, 0xc800, 0xc800, 0xc000, 0xc000, 0xca80, 0xc800, 0xc800, 0xca80, 0xc000, 0xc000, 0xc000, 0xc3c0, 0xc3c0, 0xc3c0, 0xc3c0, 0xc3c0, 0xc3c0, 0xc300, 0xc000, 0xc000, 0xc000, 0xc000, 0xcccc, 0xcccc, 0xc0c0, 0xc0c0, 0xcc00, 0xcc00, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xffff };

//const unsigned char TILE_PI[] =  { 0x00, 0x00, 0x7c, 0x28, 0x28, 0x28, 0x4c, 0x00 };
const unsigned char TILE_ER[] =  { 0xe0, 0x80, 0xe0, 0x8c, 0xea, 0x0c, 0x0a, 0x0a };
const unsigned char TILE_GR[] =   { 0xff, 0x89, 0x8d, 0x8b, 0xc9, 0xb9, 0x91, 0xfe };
const unsigned char TILE_F[] =   { 0x7e, 0x80, 0x88, 0x90, 0xa4, 0xa4, 0x98, 0x01 };
const unsigned char TILE_F_IN[] = { 0x81, 0x7f, 0x67, 0x5f, 0x5b, 0x7b, 0x67, 0xfe };
//const unsigned char TILE_0[] =   { 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF };
const unsigned char SP_PIR[] =   { 0x18, 0x3c, 0x74, 0x78, 0x3c, 0x7e, 0x38, 0x66 };
const unsigned char SP_PWR[] =   { 0x18, 0x3c, 0x74, 0x78, 0x3c, 0x7c, 0x7c, 0x28 };
const unsigned char SP_PJR[] =   { 0x18, 0x3c, 0x74, 0x78, 0x7e, 0x3c, 0x68, 0x04 };

const unsigned char SP_PIL[] =   { 0x18, 0x3c, 0x2e, 0x1e, 0x3c, 0x7e, 0x1c, 0x66 };
const unsigned char SP_PWL[] =   { 0x18, 0x3c, 0x2e, 0x1e, 0x3c, 0x3e, 0x3e, 0x14 };
const unsigned char SP_PJL[] =   { 0x18, 0x3c, 0x2e, 0x1e, 0x7e, 0x3c, 0x16, 0x20 };

const unsigned char SCREEN_WIDTH = 16;
const unsigned char SCREEN_HEIGHT = 8;


//Frame buffer
unsigned char buffer[1024];

//map data
unsigned int *level;
unsigned char *tileArray[4];
unsigned int levelX = 0;


//player data
unsigned int Ppos[2] = {32*8,40*8};//x,y, measured from the top left corner, divide by 8 (or >>3) to get the pixel position, and by 8 again to get tile value
float Pvel[2] = {0,0};//x,y, measured from the top left corner
unsigned int Acc = 15;
unsigned int onGround = 0;
unsigned int jumpCounter = 0;
//unsigned char playerSprites[4];


//general engine data
unsigned char isTimerFinished = 0;
//unsigned int key;//the key that is pressed
unsigned int timer;//for initialising the number generator
unsigned int timePerFrame = 38;



// TO DO:
// stop left drift
//
// add character sprites
// add functionality for other sprites (turtle etc.)
// title screen and inbetween level screens
// add more background tiles
// add new interactable blocks



//******************************************************************************************************************************************************************


//definitions (not actullly called that)
void drawLevel(signed int Xstart);
//theses do not check if you are attempting to draw offscreen
//it will crash horibly if you try
void drawTile(unsigned char x, unsigned char y, unsigned char pixelOffset, unsigned char *tile);//this one will overwrite the background
void drawByScreenValues(unsigned char x, unsigned char y, unsigned char *sprite);//will not overwrite background

void dealWithKeys();
void movePlayer();
void reset();


void timerFinished(){//sets the flag to say that the frame has finished
  isTimerFinished = 1;
}

//******************************************************************************************************************************************************************

//the main loop
int AddIn_main(int isAppli, unsigned short OptionNum){
  //unsigned char swapholder;// variable used to swap two others
  reset();

  while (!KeyDown(57)){//key != 0x2f
    timer++;
    isTimerFinished = 0;//start the frame timer
    SetTimer(ID_USER_TIMER1, timePerFrame, timerFinished);
    memset(&buffer,0,1024);




    drawLevel(levelX);//levelX

    dealWithKeys();
    movePlayer();
    //PlotPixel(levelX,1,buffer,1);

    // if(timer%2 ==0){
    //   memset(&buffer,0,1024);
    // }
    // if(KeyDown(71)){

    if(Ppos[1]<(1<<9)){
      if(Pvel[0]<0){
        if(onGround){
          if((timer%2)&& (Pvel[0]<-2)){
            drawByScreenValues((Ppos[0]>>3), Ppos[1]>>3, &SP_PWL);
          }else{
            drawByScreenValues((Ppos[0]>>3), Ppos[1]>>3, &SP_PIL);
          }
        }else{
          drawByScreenValues((Ppos[0]>>3), Ppos[1]>>3, &SP_PJL);
        }

      }else{
        if(onGround){
          if((timer%2) && (Pvel[0]>2)){
            drawByScreenValues((Ppos[0]>>3), Ppos[1]>>3, &SP_PWR);
          }else{
            drawByScreenValues((Ppos[0]>>3), Ppos[1]>>3, &SP_PIR);
          }
        }else{
          drawByScreenValues((Ppos[0]>>3), Ppos[1]>>3, &SP_PJR);
        }

      }
      //drawByScreenValues((Ppos[0]>>3), Ppos[1]>>3, &TILE_0);
    }


    // }



    // if(isTimerFinished == 0){
    //   PlotPixel(1, 1, buffer, 0);
    // }else{
    //   PlotPixel(1, 1, buffer, 1);
    // }
    DrawAll(&buffer);// Draw buffer to screen
    while(isTimerFinished == 0){// a not very nice way of waiting
      //swapholder = PRGM_GetKey();
      //key = (swapholder == 0) ? key : swapholder;
      //Sleep(14);
    }
    //Sleep(5);
  }
  Reset_Calc();//a terrible way to exit the program
  return 1;
}


//******************************************************************************************************************************************************************

void dealWithKeys(){
  // if(KeyDown(28)){//up
  //   //Ppos[1]--;
  //   Pvel[1] -= ((Acc + Pvel[1])/4);
  // }
  // if(KeyDown(37)){//down
  //   //Ppos[1]++;
  //   Pvel[1] += ((Acc - Pvel[1])/4);
  // }
  if(KeyDown(79)){//shift (b - run)
    Acc = 30;
  }else{
    Acc = 15;
  }
  if(!onGround){
    Acc = Acc/2;
  }
  if(KeyDown(38)){//left
    //Ppos[0]--;
    Pvel[0] -= ((Acc + Pvel[0])/4);
  }else if(KeyDown(27)){//right
    //Ppos[0]++;
    Pvel[0] += ((Acc - Pvel[0])/4);
  }else{
    Pvel[0] *= 0.4f;
  }
  if(KeyDown(69)){//alpha (a -jump)
    //onGround = 0;
    if(onGround){
      jumpCounter = 6;
      onGround = 0;
    }
    if(jumpCounter){
      Pvel[1] -= 6.9f;
      jumpCounter--;
    }else{
      Pvel[1] -= 1;
    }
  }


  // "a", "b", "start" and "select" buttons?

}

void movePlayer(){
  unsigned int constant;


  //...*
  //....
  //....
  //....
  //collides based on this pixel


  //Collision

  //check if on screen
  if(Ppos[1]>511 && Ppos[1]<0x0fff){
    if( (*(level+((Ppos[0]-8)>>6)) & 0xc000 ) | (*(level+((Ppos[0]-64)>>6)) & 0xc000 ) ){
      //there is a tile on the bottom row
      Ppos[1] = 384;
    }else{
      reset();
      return;
    }
  }

  // x collision
  if(Pvel[0]<0){//if(isNegative)
    //moving left
    constant = (*(level+((Ppos[0]-72)>>6)));
  }else{
    //moving right
    constant = (*(level+((Ppos[0])>>6)));
  }
  if( ( constant & (0x03<<(((Ppos[1])>>6)<<1)) ) |  (constant & (0x03<<(((Ppos[1]+56)>>6)<<1)) ) ) {//
    Pvel[0] = 0;
    Ppos[0] = ((Ppos[0]+32)>>6)<<6;
  }

  // y collision
  if(Pvel[1]<0){//if(isNegative)
    //moving up
    constant = (0x03<<(((Ppos[1]-8)>>6)<<1));
    if( ((*(level+((Ppos[0]-64)>>6))) & constant) | ((*(level+((Ppos[0]-8)>>6))) & constant) ){
      Pvel[1] = 0;
      Ppos[1] = ((Ppos[1]+32)>>6)<<6;
    }else{
      onGround = 0;
    }
  }else{
    //moving down
    constant = 0x03<<(((Ppos[1]+64)>>6)<<1);
    if( ((*(level+((Ppos[0]-64)>>6))) & constant ) | ((*(level+((Ppos[0]-8)>>6))) & constant ) ){
      Pvel[1] = 0;
      Ppos[1] = ((Ppos[1]+32)>>6)<<6;
      onGround = 1;
    }else{
      onGround = 0;
    }
  }






  //  PlotPixel(((Ppos[0]-72)>>3)-levelX, (Ppos[1])>>3, buffer, 1);
  //
  // if( (*(level+((Ppos[0]-72)>>6))) & (0x03<<(((Ppos[1])>>6)<<1)) ){//
  //   //its colliding?
  //   PlotPixel(1, 1, buffer, 1);
  // }



  Ppos[0] += Pvel[0];
  Ppos[1] += Pvel[1];

  if(onGround){
    Pvel[0] *= 0.75f;
    Pvel[1] *= 0.75f;
  }else{
    Pvel[0] *= 0.97f;
    Pvel[1] *= 0.97f;
  }

  Pvel[1] += 2.5;//gravity



  //move the screen when the player is near the edges, and not in the middle
  if(((Ppos[0])>>3) > (levelX+(10<<3))){
    levelX = (Ppos[0]/8) - (10<<3);
  }else
  if((Ppos[0]>>3) < (levelX+(6<<3))){
    levelX = (Ppos[0]>>3)-(6<<3);
    if(levelX &0xF000){levelX = 0;}//don't move past the start
  }
}



void drawLevel(signed int Xstart){
  unsigned char xInGrid; //the leftmost cell that appears on the screen
  unsigned char pixelOffset; //for how many pixels is the first column off screen
  unsigned char i, j;
  unsigned int mask, tileIndex;

  xInGrid = Xstart>>3;
  pixelOffset = Xstart%8;

  //DrawSprite8(15*8, 1, &buffer, FLOOR_0, 0);

  for(i=0; i<SCREEN_WIDTH+1; i++){//the plus one is to avoid any seams along the screen boundry
    mask = 0x03;
    for(j=0; j<SCREEN_HEIGHT; j++){
      tileIndex = ((*(level+xInGrid+i))&mask);
      if(tileIndex){//==1
        //DrawSprite8(i*8, j*8, &buffer, floorTile, 0);
        drawTile(i, j, pixelOffset, tileArray[tileIndex>>(j<<1)]);
      }
      mask = mask<<2;
    }
  }

}

void drawTile(unsigned char x, unsigned char y, unsigned char pixelOffset, unsigned char *tile){//this one will overwrite the background (for the tile drawing)
  unsigned char k;
  unsigned int current;

  unsigned char *position;


  for(k=0; k<8; k++){
    current = *(tile + k)<<(pixelOffset);
    //*(buffer +x +(y*8+k)*SCREEN_WIDTH) = current;
    position = (buffer +x +(y*8+k)*SCREEN_WIDTH);
    if(x > 0){
      *(position -1) |= (unsigned char)(current>>8);//don't do first column
    }
    if(x < 16){
      *position = (unsigned char)(current); //don't do last column
    }
  }

}

void drawByScreenValues(unsigned char x, unsigned char y, unsigned char *sprite){//will not overwrite background (for sprite drawing)
  unsigned char k, xInGrid, pixelOffset;
  unsigned int current;

  unsigned char *position;

  x -= levelX;

  xInGrid = x>>3; //the leftmost cell that appears on the screen
  pixelOffset = x%8;

  for(k=0; k<8; k++){
    //if(y-k<0){return;}//exit if drawing offscreen
    current = *(sprite + k)<<(8-pixelOffset);
    position = (buffer +xInGrid +(y+k)*SCREEN_WIDTH);
    if(x > 0){
      *(position -1) |= (unsigned char)(current>>8);//don't do first column
    }
    if(x < SCREEN_WIDTH*8){
      *position |= (unsigned char)(current);//don't do last column
    }
  }

}


void reset(){
  level = LEVEL_0_2;
  tileArray[0] = TILE_ER;
  tileArray[1] = TILE_F_IN;
  tileArray[2] = TILE_F;
  tileArray[3] = TILE_GR;

  levelX = 0;


  Ppos[0] = 32*8;
  Ppos[1] = 40*8;//x,y, measured from the top left corner, divide by 8 (or >>3) to get the pixel position, and by 8 again to get tile value
  Pvel[0] = 0;
  Pvel[1] = 0;//x,y, measured from the top left corner
  Acc = 15;
  onGround = 0;
  jumpCounter = 0;
  Sleep(timePerFrame);
}




//****************************************************************************
//**************                                              ****************
//**************                 Notice!                      ****************
//**************                                              ****************
//**************  Please do not change the following source.  ****************
//**************                                              ****************
//****************************************************************************


#pragma section _BR_Size
unsigned long BR_Size;
#pragma section


#pragma section _TOP

//****************************************************************************
//  InitializeSystem
//
//  param   :   isAppli   : 1 = Application / 0 = eActivity
//              OptionNum : Option Number (only eActivity)
//
//  retval  :   1 = No error / 0 = Error
//
//****************************************************************************
int InitializeSystem(int isAppli, unsigned short OptionNum)
{
  return INIT_ADDIN_APPLICATION(isAppli, OptionNum);
}

#pragma section

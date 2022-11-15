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
const unsigned char LEVEL_1_1[] = { 0xff, 0xff, 0x80, 0x80, 0x80, 0xc0, 0x80, 0x88, 0x80, 0xc0, 0xe0, 0xe0, 0xe0, 0x80, 0x80, 0x80, 0x9c, 0x80, 0x80, 0x80, 0x84, 0x84, 0x84, 0x84, 0x84, 0xc0, 0xc0, 0xd8, 0xc0, 0x80, 0x80, 0xff };
const unsigned char LEVEL_0[]   = { 0xff, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0xff };
const unsigned char TILE_0[] =   { 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF };
const unsigned char TILE_1[] =   { 0xff, 0x89, 0x8d, 0x8b, 0xc9, 0xb9, 0x91, 0xfe };


const unsigned char SCREEN_WIDTH = 16;
const unsigned char SCREEN_HEIGHT = 8;


//Frame buffer
unsigned char buffer[1024];

//map data
unsigned char *level = LEVEL_1_1;
unsigned char *floorTile = TILE_1;
unsigned int levelX = 0;


//player data
unsigned int Ppos[] = {32*8,40*8};//x,y, measured from the top left corner, divide by 8 (or >>3) to get the pixel position, and by 8 again to get tile value
float Pvel[] = {0,0};//x,y, measured from the top left corner
unsigned int Acc = 15;
unsigned int onGround = 0;
unsigned int jumpCounter = 0;


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
void drawTile(unsigned char i, unsigned char j, unsigned char pixelOffset);//this one will overwrite the background
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

  while (1){//key != 0x2f
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
      drawByScreenValues((Ppos[0]>>3), Ppos[1]>>3, &TILE_0);
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
  //   Pvel[1] -= ((Acc + Pvel[1])/4);
  // }
  // if(KeyDown(37)){//down
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
    Pvel[0] -= ((Acc + Pvel[0])/4);
  }
  if(KeyDown(27)){//right
    Pvel[0] += ((Acc - Pvel[0])/4);
  }
  if(KeyDown(69)){//alpha (a -jump)
    //onGround = 0;
    if(onGround){
      jumpCounter = 6;
      onGround = 0;
    }
    if(jumpCounter){
      Pvel[1] -= 7.0f;
      jumpCounter--;
    }else{
      Pvel[1] -= 1;
    }
  }

  // if(timer%100 ==0){
  //     Pvel[1] = -60;
  //     onGround =0;
  // }
  //     onGround--;
  //   }else{
  //     Pvel[1] -= 2;
  //   }
  // }

  // "a", "b", "start" and "select" buttons?

}

void movePlayer(){
  unsigned char constant;


  //...*
  //....
  //....
  //....
  //collides based on this pixel


  //Collision

  //check if on screen
  if(Ppos[1]>511 && Ppos[1]<0x0fff){
    if( (*(level+((Ppos[0]-8)>>6)) & 0x01 ) | (*(level+((Ppos[0]-64)>>6)) & 0x01 ) ){
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
    constant = *(level+((Ppos[0]-65)>>6));
  }else{
    //moving right
    constant = *(level+((Ppos[0]+8)>>6));
  }
  if( ( constant & (0x01<<(Ppos[1]>>6)) ) |  (constant & (0x01<<((Ppos[1] +56)>>6)) ) ) {//
    Pvel[0] = 0;
    Ppos[0] = ((Ppos[0]+32)>>6)<<6;
  }

  // y collision
  if(Pvel[1]<0){//if(isNegative)
    //moving up
    constant = 0x01<<((Ppos[1]-8)>>6);
    if( (*(level+((Ppos[0]-8)>>6)) & constant ) | (*(level+((Ppos[0]-64)>>6)) & constant ) ){
      Pvel[1] = 0;
      Ppos[1] = ((Ppos[1]+32)>>6)<<6;
    }else{
      onGround = 0;
    }
  }else{
    //moving down
    constant = 0x01<<((Ppos[1]+64)>>6);
    if( (*(level+((Ppos[0]-8)>>6)) & constant ) | (*(level+((Ppos[0]-64)>>6)) & constant ) ){
      Pvel[1] = 0;
      Ppos[1] = ((Ppos[1]+32)>>6)<<6;
      onGround = 1;
    }else{
      onGround = 0;
    }
  }




  // if((*(level+(Ppos[0]>>6))) & (0x01<<(Ppos[1]>>6))){//
  //   //its colliding?
  //   PlotPixel(1, 1, buffer, 1);
  // }



  Ppos[0] += Pvel[0];
  Ppos[1] += Pvel[1];

  if(onGround){
    Pvel[0] *= 0.70f;
    Pvel[1] *= 0.70f;
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
  unsigned char mask;

  xInGrid = Xstart>>3;
  pixelOffset = Xstart%8;

  //DrawSprite8(15*8, 1, &buffer, FLOOR_0, 0);

  for(i=0; i<SCREEN_WIDTH+1; i++){//the plus one is to avoid any seams along the screen boundry
    mask = 0x01;
    for(j=0; j<SCREEN_HEIGHT; j++){
      if(((*(level+xInGrid+i))&mask)){//==1
        //DrawSprite8(i*8, j*8, &buffer, floorTile, 0);
        drawTile(i, j, pixelOffset);
      }
      mask = mask<<1;
    }
  }

}

void drawTile(unsigned char x, unsigned char y, unsigned char pixelOffset){//this one will overwrite the background (for the tile drawing)
  unsigned char k;
  unsigned int current;

  unsigned char *position;


  for(k=0; k<8; k++){
    current = *(floorTile + k)<<(pixelOffset);
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

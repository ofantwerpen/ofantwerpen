//
//  BlobFinder.h
//  ofxKinect
//
//  Created by Kris Temmerman on 10/05/11.
//  Copyright 2011 Neuro Productions. All rights reserved.
//
#pragma once

#import "ofImage.h"
#import "Blob.h"


#import "mcPoint.h"
#import "mcCube.h"


#include <vector>
#include <stdio.h>
#include <string.h>
#include "Constants.h"

class BlobFinder {
public:
    
	BlobFinder();
    
    
    
    
    // triangulation
    
    mcPoint *points;
    mcCube *cubes;
  
    float cubesPos[1500];
    int cubeCount;
    float triangles[90000];// max triangles *9 is gok
    int triangleCount;
    
    

    
  int stepSize;
    
    int numPoints;
    int sw;
    int sh;
    
    // triangulation utils;
    void calculateTriangles(  mcCube *cubes, mcPoint *points, unsigned char *pixelData );
    void addTriangle(mcPoint *point1,mcPoint *point2,mcPoint *point3);
    mcPoint getCrossPoint(mcPoint *onPoint,mcPoint *ofPoint,bool isHorizontal,unsigned char *depthPixelsBack);
    
    void addCube(mcPoint *point);
    
    
    
    
    
    
    void update(float rawdataIn[KINECT_SIZE]);
    void draw();

    bool findNextEmptyPixel();
    
  //  PersonHandler *personHandler;
    
    ofImage inputImage;
    ofImage outputImage;
    
    
   
    unsigned char *rawdataOutput;
      unsigned char *rawdataFilterd;
    
    int getArrPos(int x, int y) {return KINECT_W * y + x; } 
    
    int nonEmptyPixelPos;
    int startX;
    int startY;
    int test;
    float chekValue;
    vector<Blob*> blobVector;
    float rawdata [KINECT_SIZE];
   
};
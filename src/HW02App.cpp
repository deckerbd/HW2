/**
*@Author: Ben Decker
*@Date: 24 September 2012
*@Assignment: Homework 2: Placing things on top of other things
*@Additional Notes: Syntax for KeyEvents and HW01 outline used from jordankomnick (https://github.com/jordankomnick)
**/

#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "cinder/gl/Texture.h"
#include "cinder/ImageIo.h"
#include "boost/date_time/posix_time/posix_time.hpp"
#include "node.h"
#include "Resources.h"
#include <cstdlib> 
#include <iostream>
#include <math.h>
#include <cinder\app\App.h>
#include <cinder\Text.h>
#include <cinder\Font.h>

using namespace ci;
using namespace ci::app;
using namespace std;

class HW2App : public AppBasic {
  public:
	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
	/**set the three parts of a pixel using just the x and y value of and the color
	*/
	void setPixel(uint8_t* ar, int x,int y, Color8u c);
	/**
	*draw a rectangle givent he top left corner and its width and hight
	*/
	void drawRect(uint8_t* ar, int x,int y, int w, int h, Color8u c);

	void keyDown(KeyEvent event);

  private:
	Surface* mySurface_;
	Surface tex;
	uint8_t* pixelArray;
	node* lst;
	node* temp;
	node* background;
	node* rec1;
	node* rec2;
	node* rec3;
	node* rec4;
	node* rec5;
	char shape;
	TextLayout* text;
	Font font;
	int help;
};

void HW2App::setPixel(uint8_t* ar, int x,int y, Color8u c)
{
	//set all three of the colors individually using the cordinates of the pixel
	ar[y * 1024 * 3 + 3 * x] = c.r;
	ar[y * 1024 * 3 + 3 * x + 1] = c.g;
	ar[y * 1024 * 3 + 3 * x + 2] = c.b;

};

void HW2App::drawRect(uint8_t* ar, int x,int y, int w, int h, Color8u c)
{
	//loop through all of the pixels in the rectangle and change their color
	for(int i = x; i < x + w; i++){
		for(int j = y; j < y + h; j++){
			setPixel(ar, i, j, c);
		};
	};

};

void HW2App::keyDown( KeyEvent event ) {
	//if the key pressed is one of the shapes then set shape to that shape's key
	if(event.getChar() == 'q' || event.getChar() == 'w'|| event.getChar() == 'e'|| event.getChar() == 'r'|| event.getChar() == 't'|| event.getChar() == 'y'){
	shape = event.getChar();
	};
	// toggle help
	if(event.getCode() == 47){
		if(help == 1)
			help = 0;
		else
			help = 1;
	};
	// call reverse list method for key f
	if(event.getChar() == 'f'){
		reverse(lst);
	};

	// for key a move the coresponding shape up in the list
	if( event.getChar() == 'a' ) {
		if(shape == 'q'){
			if(background->next != NULL){
				remove(background);
				insertAfter(background, background->next, lst);
			};
		};
		if(shape == 'w'){
			if(rec1->next != NULL){
				remove(rec1);
				insertAfter(rec1, rec1->next, lst);
			};
		};
		if(shape == 'e'){
			if(rec2->next != NULL){
				remove(rec2);
				insertAfter(rec2, rec2->next, lst);
			};
		};
		if(shape == 't'){
			if(rec3->next != NULL){
				remove(rec3);
				insertAfter(rec3, rec3->next, lst);
			};
		};
		if(shape == 'r'){
			if(rec4->next != NULL){
				remove(rec4);
				insertAfter(rec4, rec4->next, lst);
			};
		};
		if(shape == 'y'){
			if(rec5->next != NULL){
				remove(rec5);
				insertAfter(rec5, rec5->next, lst);
			};
		};
    };

	//for key z move the coresponding shape back in the list
	if( event.getCode() == 'z' ) {
		if(shape == 'q'){
			if(background->prev->prev != NULL){
				remove(background);
				insertAfter(background, background->prev->prev, lst);
			};
		};
		if(shape == 'w'){
			if(rec1->prev->prev != NULL){
				remove(rec1);
				insertAfter(rec1, rec1->prev->prev, lst);
			};
		};
		if(shape == 'e'){
			if(rec2->prev->prev != NULL){
				remove(rec2);
				insertAfter(rec2, rec2->prev->prev, lst);
			};
		};
		if(shape == 't'){
			if(rec3->prev->prev != NULL){
				remove(rec3);
				insertAfter(rec3, rec3->prev->prev, lst);
			};
		};
		if(shape == 'r'){
			if(rec4->prev->prev != NULL){
				remove(rec4);
				insertAfter(rec4, rec4->prev->prev, lst);
			};
		};
		if(shape == 'y'){
			if(rec5->prev->prev != NULL){
				remove(rec5);
				insertAfter(rec5, rec5->prev->prev, lst);
			};
		};
    };
	// for the arrow keys move the selected shape in the right derection
	// up arrow
	if(event.getCode() == 273){
		if(shape == 'q'){
		};
		if(shape == 'w'){
			move(rec1, 0, 10);
		};
		if(shape == 'e'){
			move(rec2, 0, 10);
		};
		if(shape == 'r'){
			move(rec3, 0, 10);
		};
		if(shape == 't'){
			move(rec4, 0, 10);
		};
		if(shape == 'y'){
			move(rec5, 0, 10);
		};
	};
	// down arrow
	if(event.getCode() == 274){
		if(shape == 'q'){
		};
		if(shape == 'w'){
			move(rec1, 0, -10);
		};
		if(shape == 'e'){
			move(rec2, 0, -10);
		};
		if(shape == 'r'){
			move(rec3, 0, -10);
		};
		if(shape == 't'){
			move(rec4, 0, -10);
		};
		if(shape == 'y'){
			move(rec5, 0, -10);
		};
	}; 
	// right arrow
	if(event.getCode() == 275){
		if(shape == 'q'){
		};
		if(shape == 'w'){
			move(rec1, 10, 0);
		};
		if(shape == 'e'){
			move(rec2, 10, 0);
		};
		if(shape == 'r'){
			move(rec3, 10, 0);
		};
		if(shape == 't'){
			move(rec4, 10, 0);
		};
		if(shape == 'y'){
			move(rec5, 10, 0);
		};
	};
	// left arrow
	if(event.getCode() == 276){
		if(shape == 'q'){
		};
		if(shape == 'w'){
			move(rec1, -10, 0);
		};
		if(shape == 'e'){
			move(rec2, -10, 0);
		};
		if(shape == 'r'){
			move(rec3, -10, 0);
		};
		if(shape == 't'){
			move(rec4, -10, 0);
		};
		if(shape == 'y'){
			move(rec5, -10, 0);
		};
	};
};

void HW2App::setup()
{
	//create surface
	mySurface_ = new Surface(1024,1024,false);
	// set variable to toggle help
	help = 1;
	//set font of help
	font = Font( "", 14.0 );
	// set up text for the help
	text = new TextLayout();
	text->setFont(font);
	text->setColor( ColorA( 1.0f, 1.0f, 1.0f, 1.0f ) );
	text->addLine("Select a shape/layer to modify by using the following keys:");
	text->addLine("	q: Background");
	text->addLine("	w: Red Rectangle");
	text->addLine("	e: Green Rectangle");
	text->addLine("	r: Blue Rectangle");
	text->addLine("	t: Yellow Rectangle");
	text->addLine("	y: Purple Rectangle");
	text->addLine("Once a shape is selected:");
	text->addLine("	a: Moves the shape up in the list");
	text->addLine("	z: Moves the shape back in the list");
	text->addLine("	Arrow Keys: Move the shape around");
	text->addLine("Additional key commands:");
	text->addLine("	?: Toggle help menu");
	text->addLine("	f: Reverses layer list");
	// make a surface out of the text
	tex = text->render(true,true);

	//set initial selected shape
	shape = 'q';

	//create head of shape list
	lst = new node();
	temp = lst;
	//add the shapes in
	insertAfter(new node(pixelArray,0,0,640,480,Color8u(0, 0, 255)),temp,lst);
	background = lst->next;
	temp = temp->next;
	insertAfter(new node(pixelArray,100,100,100,100,Color8u(255, 0, 0)),temp,lst);
	temp = temp->next;
	rec1 = temp;
	insertAfter(new node(pixelArray,1,150,75,75,Color8u(0, 255, 0)),temp,lst);
	temp = temp->next;
	rec2 = temp;
	insertAfter(new node(pixelArray,300,10,80,80,Color8u(0, 125, 255)),temp,lst);
	temp = temp->next;
	rec3 = temp;
	insertAfter(new node(pixelArray,300,150,60,90,Color8u(255, 255, 0)),temp,lst);
	temp = temp->next;
	rec4 = temp;
	insertAfter(new node(pixelArray,500,10,125,125,Color8u(0, 255, 255)),temp,lst);
	rec5 = temp->next;
	
};

void HW2App::mouseDown( MouseEvent event )
{
};

void HW2App::update()
{
	uint8_t* pixelArray = (*mySurface_).getData();

	//set temp back to the start of the list of shapes
	temp = lst;
	temp = temp->next;

	//draw the shapes in the list
	while(temp != NULL){
		drawRect(pixelArray, temp->x, temp->y, temp->w, temp->h, temp->c);
		temp = temp->next;
	};

};

void HW2App::draw()
{
	//show help or shapes
	if(help == 1){
	gl::draw(tex);
	}
	else
	gl::draw(*mySurface_);
};

CINDER_APP_BASIC( HW2App, RendererGl )

#include "cinder/gl/gl.h"
#include "cinder/app/AppBasic.h"
#include "node.h"
#include "cinder/Rand.h"

using namespace ci;
using namespace ci::app;
using namespace std;

node::node(){
	next = NULL;
	prev = NULL;

	//rest
	x = NULL;
	y = NULL;
	w = NULL;
	h = NULL;
	c = Color(255,0,0);
};

node::node(uint8_t* ar, int xx,int yy, int ww, int hh, Color8u cc){
	next = NULL;
	prev = NULL;
	x = xx;
	y = yy;
	w = ww;
	h = hh;
	c = cc;
};

void insertAfter(node* insert, node* after, node* head){
	if(insert != NULL && after != NULL && head != NULL){
		if(insert == head->next){
		head->next = after;
		};

		insert->next = after->next;

		insert->prev = after;

		if(after->next != NULL)
			after->next->prev = insert;

		after->next = insert;

	};
};

void remove(node* out){
	if(out != NULL){
	if(out->next == NULL){
		out->prev->next = NULL;
	}
	else{
		out->prev->next = out->next;
		out->next->prev = out->prev;
	}
	};
};

void move(node* move, int x, int y){

			move->x = move->x + x;
			move->y = move->y - y;
};

void reverse(node* head){
	node* temp;
	node* hold;
	temp = head->next;

	temp->prev = temp->next;
	temp->next = NULL;

	temp = temp->prev;

	while(temp->next != NULL){
		hold = temp->prev;
		temp->prev = temp->next;
		temp->next = hold;
		temp = temp->prev;
	};
	temp->next = temp->prev;
	temp->prev = head;
	head->next = temp;
};
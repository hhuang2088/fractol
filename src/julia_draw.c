#include "fractal.h"

static void julia_set_pixel_color(t_state *state, double newRe, double newIm, int i)
{

  state->rgb->r = i % 256 * (i < state->max);
  state->rgb->g = 255 * (i < state->max) * (newRe * newRe + newIm * newIm > 4);
  state->rgb->b = 255 * !(i < state->max);
}

void julia_draw(t_state *state)
{
  double cRe;
	double cIm;
	double newRe;
	double newIm;
	double oldRe;
	double oldIm;
	int			row;
	int			col;
	int			i;
	/*
  //each iteration, it calculates: new = old*old + c, where c is a constant and old starts at current pixel
  double cRe, cIm;           //real and imaginary part of the constant c, determinate shape of the Julia Set
  double newRe, newIm, oldRe, oldIm;   //real and imaginary parts of new and old
  double zoom = 1, moveX = 0, moveY = 0; //you can change these to zoom and change position
  ColorRGB color; //the RGB color value for the pixel
  int maxIterations = 300; //after how much iterations the function should stop
	*/
  //pick some values for the constant c, this determines the shape of the Julia Set
  cRe = -0.7;
  cIm = 0.27015;
	row = 0;
  //loop through every pixel
  while (row < state->height)
	{
		col = 0;
	  while (col < state->width)
	  {
	    //calculate the initial real and imaginary part of z, based on the pixel location and zoom and position values
	    newRe = 1.5 * (col - state->width / 2) / (0.5 * state->zoom * state->width) - state->x_displacement;
	    newIm = (row - state->height / 2) / (0.5 * state->zoom * state->height) - state->y_displacement;
	    //i will represent the number of iterations
	    i = 0;
	    //start the iteration process
	    while (i < state->max)
	    {
	      //remember value of previous iteration
	      oldRe = newRe;
	      oldIm = newIm;
	      //the actual iteration, the real and imaginary part are calculated
	      newRe = oldRe * oldRe - oldIm * oldIm + cRe;
	      newIm = 2 * oldRe * oldIm + cIm;
	      //if the point is outside the circle with radius 2: stop
	      if((newRe * newRe + newIm * newIm) > 4)
					break;
				++i;
	    }
	    //use color model conversion to get rainbow palette, make brightness black if maxIterations reached
			julia_set_pixel_color(state, newRe, newIm, i);
	    //draw the pixel
			pixel_draw_single_byte(state, col, row);
			++col;
	  }
		++row;
	}
}

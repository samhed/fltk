//
// Icon test program for the Fast Light Tool Kit (FLTK).
//
// Copyright 1998-2021 by Bill Spitzak and others.
//
// This library is free software. Distribution and use rights are outlined in
// the file "COPYING" which should have been included with this file.  If this
// file is missing or damaged, see the license at:
//
//     https://www.fltk.org/COPYING.php
//
// Please see the following page on how to report bugs and issues:
//
//     https://www.fltk.org/bugs.php
//

#include <FL/Fl.H>
#include <FL/Fl_Double_Window.H>
#include <FL/Fl_Choice.H>
#include <FL/Fl_RGB_Image.H>

static Fl_Double_Window *win;

void choice_cb(Fl_Widget *, void *v) {
  Fl_Color c = (Fl_Color)fl_uint(v);
  uchar buffer[32*32*3];
  Fl_RGB_Image icon(buffer, 32, 32, 3);
  icon.color_average(c, 0.0);
  win->icon(&icon);
}

Fl_Menu_Item choices[] = {
  {"Red",   0, choice_cb, fl_voidptr(FL_RED)},
  {"Green", 0, choice_cb, fl_voidptr(FL_GREEN)},
  {"Blue",  0, choice_cb, fl_voidptr(FL_BLUE)},
  {0}
};

int main(int argc, char **argv) {
  Fl_Double_Window window(400,300);
  win = &window;

  Fl_Choice choice(80,100,200,25,"Colour:");
  choice.menu(choices);
  choice.callback(choice_cb);
  choice.when(FL_WHEN_RELEASE|FL_WHEN_NOT_CHANGED);

  window.end();
  window.show(argc,argv);
  return Fl::run();
}

#ifndef SVG_H
#define SVG_H

#include <vector>
#include <string>
#include <iostream>

using namespace std;

const vector<string> COLORS {"#7FFF00", "#DC143C", "#1E90FF", "#FFA500", "#8B008B"};
//const vector<string> COLORS {"black"};
int lastColorIndex = -1;

const bool OPACITY_CHANGE = true;
const bool USE_STROKE = false;
const size_t SVG_MAX_GIST_WIDTH = 80;

const string STROKE_COLOR = "black";
const auto STROKE_WIDTH = 2;
const auto TEXT_X = 20;
const auto TEXT_Y = 20;
const auto TEXT_WIDTH = 60;
const auto BIN_HEIGHT = 30;
const auto BLOCK_WIDTH = 15;

void svgOutput(vector<size_t> bins, size_t maxBinCount);
void svgHeader(double width, double height);
void svgFooter();
void svgText(double x, double y, string text);
void svgRect(double x, double y, double width, double height, string color, double opacity);
#endif
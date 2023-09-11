#include "svg.h"

string getRandomColor() {
    size_t index = rand() % COLORS.size();
    if (index == lastColorIndex) {
        index = (lastColorIndex + 1) % COLORS.size();
    }
    lastColorIndex = index;
    return COLORS[index];
}

double getOpacity(size_t bin, size_t maxBinCount) {
    if (maxBinCount == 0) {
        return 0;
    }
    double opacity = bin / static_cast<double>(maxBinCount);
    if (opacity < 0.2) opacity = 0.2;
    return opacity;
}

void svgOutput(vector<size_t> bins, size_t maxBinCount) {
    double coeff = 1;
    if (maxBinCount > SVG_MAX_GIST_WIDTH) {
        coeff = SVG_MAX_GIST_WIDTH / static_cast<double>(maxBinCount);
    }
    svgHeader((TEXT_X + TEXT_WIDTH) + maxBinCount * coeff * BLOCK_WIDTH + STROKE_WIDTH*USE_STROKE, bins.size()*BIN_HEIGHT);
    double top = 0;
    for (size_t bin : bins) {
        const double bin_width = BLOCK_WIDTH * bin * coeff;
        double opacity = 1;
        if (OPACITY_CHANGE) opacity = getOpacity(bin, maxBinCount);
        svgText(TEXT_X, top + TEXT_Y, to_string(bin));
        svgRect(TEXT_WIDTH, top, bin_width, BIN_HEIGHT, getRandomColor(), opacity);
        top += BIN_HEIGHT;
    }
    svgFooter();
    
}

void svgHeader(double width, double height) {
    cout << "<?xml version='1.0' encoding='UTF-8' ?>\n"
    << "<svg " << "width='" << width << "' height='" << height
    << "' viewBox='0 0 " << width << " " << height
    <<  "' xmlns='http://www.w3.org/2000/svg'>\n";
}

void svgText(double x, double y, string text) {
    cout << "<text x='" << x << "' y='" << y << "' style='font: bold 18px sans-serif;'>" << text << "</text>";
}

void svgRect(double x, double y, double width, double height, string color, double opacity) {
    cout << "<rect x='" << x << "' y='" << y << "' width='" << width << "' height='" << height << "' fill='" << color;
    if (USE_STROKE) {
        cout << "' stroke='" << STROKE_COLOR << "' stroke-width='" << STROKE_WIDTH;
    }
    cout << "' fill-opacity='" << opacity <<"'/>";
}

void svgFooter() {
    cout << "</svg>\n";
}
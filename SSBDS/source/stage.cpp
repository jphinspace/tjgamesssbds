#include "stage.h"
#include <vector>
#include <PA9.h>
using std::vector;

//ledge methods:
Ledge::Ledge(int xpos, int ypos, string dir) {
	x = xpos;
	y = ypos;
	direction = dir;
} // creates a new ledge

//floor methods:
Floor::Floor(int xpos, int ypos, int l, bool plat) {
	x = xpos;
	y = ypos;
	length = l;
	isplatform = plat;
} // creates a new floor
bool Floor::isPlatform() { return isplatform; } // returns isplatform
double Floor::totalrise() {
	double total = 0;
	for(int n = 0; n < (int)slopes.size(); n++) {
		total += slopes[n];
	}
	return total;
} // counts the total rise of the stage from start to finish
double Floor::getrise(int distance) {
	double total = 0;
	for(int n = x; n < distance; n++) {
		total += slopes[n-x];
	}
	return total;
} // the rise up to distance distance

//ceiling methods:
Ceiling::Ceiling(int xpos, int ypos, int l) {
	x = xpos;
	y = ypos;
	length = l;
} // creates a new ceiling

//wall methods:
Wall::Wall(int xpos, int ypos, int l, string d) {
	x = xpos;
	y = ypos;
	length = l;
	direction = d;
} // creates a new wall

char* Stage::selectTrack() {
	int trknum = PA_RandMax(musictracks.size());
	if(trknum == 0) return "";
	string temp = ("SSBDS_Files/music/" + name + "/" + musictracks[trknum] + ".mp3");
	char* path = new char[strlen(temp.c_str())];
	return path;
}

//stage methods:
void Stage::Initialize() {} 
// each subclass has it's own initialization code
string Stage::getName() { return name; }
vector<Floor> Stage::getFloors() { return floors; }
vector<Wall> Stage::getWalls() { return walls; }
vector<Ceiling> Stage::getCeilings() { return ceilings; }
vector<Ledge> Stage::getLedges() { return ledges; }
// gets stuff about the stage
Stage::~Stage() {}

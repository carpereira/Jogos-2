#define MAX_COLORS 11
#define MAX_STARTING_POINTS  7
#define MAX_SIZES 7
#define MAX_ALPHA 255


int colors[MAX_COLORS][3] = {
	{0,0,0}, //Black	
	{255,255,255}, //White	
	{255,0,0}, //Red	
	{0,0,255}, //Blue	
	{255,255,0}, //Yellow	
	{0,255,255}, //Cyan Aqua	
	{255,0,255}, //Magenta	
	{128,128,128}, //Gray	
	{128,0,0}, //Maroon	
	{0,128,0}, //Green	
	{128,0,128}, //Purple	
};

int COLOR_BLACK[3] = {0,0,0};
int COLOR_WHITE[3] = {255,255,255};
int COLOR_RED[3] = {255,0,0};
int COLOR_BLUE[3] = {0,0,255};
int COLOR_YELLOW[3] = {255,255,0};
int COLOR_CYAN_AQUA[3] = {0,255,255};
int COLOR_MAGENTA[3] = {255,0,255};
int COLOR_GRAY[3] = {128,128,128};
int COLOR_MAROON[3] = {128,0,0};
int COLOR_GREEN[3] = {0,128,0};
int COLOR_PURPLE[3] = {128,0,128};

int COLOR_BLUE_TRELLO[3] = {12, 98, 220};


int startingPoints[MAX_STARTING_POINTS][2] = {
	{0,0},
	{100,100},
	{200,200},
	{200,0},
	{0,200},
	{300,300},
	{400,500},
	// {0,0}
};


int sizes[MAX_SIZES][2] = {
	{40,20},
	{80,40},
	{80,40},
	{80,30},
	{0,0},
	{30,0},
	{0,50}
};
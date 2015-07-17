#pragma once
#include <SFML/Graphics.hpp>
#include <TGUI/TGUI.hpp>
#include <string>

static int SCREENWIDTH = 1000;
static int SCREENHEIGHT = 320;

static int CHUNKSIZE = 320;

static bool FULLSCREEN = false;

static const std::string RESOURCEPATH = "Resources";
static const std::string MAPPATH = RESOURCEPATH + "/map";
static const std::string MAP1PATH = MAPPATH + "/map1.json";

static const std::string TGUICONFBLACK = "Resources/widgets/Black.conf";
static const std::string TGUICONFWHITE = "Resources/widgets/White.conf";
static const std::string TGUICONFBABYBLUE = "Resources/widgets/BabyBlue.conf";

//static const std::string BASEPATH = SDL_GetBasePath();
//static const std::string RESOURCEPATH = BASEPATH + "Resources\\";
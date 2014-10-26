#include "Level.h"


Level::Level(const char* levelName)
{
	m_levelName = levelName;
	
	//TODO:
	//An dieser stelle besser einen unique_ptr verwenden
	//vielleicht auch move verwenden, weiﬂ nicht ob das Sinnvoll ist oder hier anwendbar
	//Vielleicht noch einen Zusatz an den levelNamen h‰ngen, damit die Namen nicht exakt gleich sind
	Scenegraph scenegraph(levelName);
	addScenegraph(&scenegraph);
}


Level::~Level()
{
}

const char* Level::getLevelName()
{
	return m_levelName;
}

void Level::addScenegraph(Scenegraph* scenegraph)
{
	m_scenegraph = scenegraph;
}

Scenegraph* Level::getScenegraph()
{
	return m_scenegraph;
}
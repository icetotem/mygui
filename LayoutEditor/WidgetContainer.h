#ifndef __WIDGET_CONTAINER_H__
#define __WIDGET_CONTAINER_H__

#include "MyGUI.h"
#include <sstream>

typedef std::vector<std::pair<Ogre::String, Ogre::String> > StringPairs;
//typedef std::map<Ogre::String, Ogre::String> MapString;
//typedef std::vector<std::pair<std::string, std::string> > MapString;

struct WidgetContainer
{
	WidgetContainer():
		relative_mode(false)
	{}
	WidgetContainer(std::string _type, std::string _skin, MyGUI::WidgetPtr _widget, std::string _name = ""):
		type(_type),
		skin(_skin),
		widget(_widget),
		name(_name),
		relative_mode(false)
	{}

	MyGUI::WidgetPtr widget;
	StringPairs mProperty;
	StringPairs mUserString;
	std::string type;
	std::string skin;
	std::string align;
	Ogre::String name;
	// not for saving
	inline std::string position(bool _percent = true)
	{
		if (relative_mode){
			MyGUI::FloatCoord coord = MyGUI::Gui::getInstance().convertIntToRelative(widget->getCoord(), widget->getParent());
			std::ostringstream stream;
			if (_percent) stream << coord.left*100 << " " << coord.top*100 << " " << coord.width*100 << " " << coord.height*100;
			else stream << coord.left << " " << coord.top << " " << coord.width << " " << coord.height;
			return stream.str();
		}
		return widget->getCoord().print();
	}
	inline std::string layer() { return widget->getLayerName(); }
	bool relative_mode;
};

class EditorWidgets{

	INSTANCE_HEADER(EditorWidgets);

public:
	void initialise();
	void shutdown();
	bool load(std::string _fileName);
	bool save(std::string _fileName);
	void loadxmlDocument(MyGUI::xml::xmlDocument * doc, bool _test = false);
	MyGUI::xml::xmlDocument * savexmlDocument();
	WidgetContainer * find(MyGUI::WidgetPtr _widget);
	WidgetContainer * find(std::string _name);
	void add(WidgetContainer * _container);
	void remove(MyGUI::WidgetPtr _widget);
	void clear();

	std::vector<WidgetContainer*> widgets;
	int global_counter;
private:
	void parseWidget(MyGUI::xml::xmlNodeIterator & _widget, MyGUI::WidgetPtr _parent, bool _test = false);
	void serialiseWidget(WidgetContainer * _container, MyGUI::xml::xmlNodePtr _node);

private:
	typedef std::map<std::string, std::string> MapString;
};

#endif // __WIDGET_CONTAINER_H__

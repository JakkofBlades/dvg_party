#ifndef _FONT_MAP_HPP_
#define _FONT_MAP_HPP_

#include <unordered_map>

#include <SFML/Graphics.hpp>

#include "logger.hpp"

class FontMap
{
public:
   FontMap(const std::string& folder, const std::string ext);

   void Add(const std::string& name);

   bool Exists(const std::string& name);

   sf::Font& GetFont(const std::string& name);

private:
   std::unordered_map<std::string, sf::Font> fonts_;

   dahl::iris::Logger log_;
   std::string folder_;
   std::string ext_;
};

#endif /* _FONT_MAP_HPP_ */

#ifndef _TEXTURE_MAP_HPP_
#define _TEXTURE_MAP_HPP_

#include <unordered_map>

#include <SFML/Graphics.hpp>

#include "logger.hpp"

class TextureMap
{
public:
   TextureMap(const std::string& folder, const std::string ext);

   void Add(const std::string& name);

   bool Exists(const std::string& name);

   sf::Texture& GetTexture(const std::string& name);

private:
   std::unordered_map<std::string, sf::Texture> textures_;

   dahl::iris::Logger log_;
   std::string folder_;
   std::string ext_;
};

#endif

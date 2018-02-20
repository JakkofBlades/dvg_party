#include "texture_map.hpp"

TextureMap::TextureMap(const std::string& folder, const std::string ext)
   : log_("TextureMap"),
     folder_(folder),
     ext_(ext)
{}

void TextureMap::Add(const std::string& name)
{
   std::string path = folder_ + name + ext_;

   sf::Texture texture;

   if(!texture.loadFromFile(path))
   {
      log_.Error() << "Failed to load image: " << name;

      path = folder_ + "null" + ext_;
      if(texture.loadFromFile(path))
      {
         log_.Error() << "No default texture specified, texture loading failed";
         return;
      }
   }

   textures_.insert(std::make_pair(name, texture));
}

bool TextureMap::Exists(const std::string& name)
{
   return textures_.find(name) != textures_.end();
}

sf::Texture& TextureMap::GetTexture(const std::string& name)
{
   if(!Exists(name))
   {
      log_.Warn() << "Texture \"" << name << ext_
                  << "\" doesn't exist yet, attempting to add";
      Add(name);
   }

   return textures_[name];
}

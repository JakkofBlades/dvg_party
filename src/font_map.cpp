#include "font_map.hpp"

FontMap::FontMap(const std::string& folder, const std::string ext)
   : log_("FontMap"),
     folder_(folder),
     ext_(ext)
{}

void FontMap::Add(const std::string& name)
{
   std::string path = folder_ + name + ext_;

   sf::Font font;

   if(!font.loadFromFile(path))
   {
      log_.Error() << "Failed to load font: " << name;

      path = folder_ + "null" + ext_;
      if(font.loadFromFile(path))
      {
         log_.Error() << "No default font specified, font loading failed";
         return;
      }
   }

   fonts_.insert(std::make_pair(name, font));
}

bool FontMap::Exists(const std::string& name)
{
   return fonts_.find(name) != fonts_.end();
}

sf::Font& FontMap::GetFont(const std::string& name)
{
   if(!Exists(name))
   {
      log_.Warn() << "Font \"" << name << ext_
                  << "\" doesn't exist, attempting to add";
      Add(name);
   }

   return fonts_[name];
}

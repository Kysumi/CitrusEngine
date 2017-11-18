#include "ContentLoader.h"
#include "TileSheet.h"
//Dank memes
void ContentLoader::LoadTileSheet(TileSheet* t)
{    
    sf::Image s;
    
    if(s.loadFromFile(*t->GetImageSource()))
    {
        std::cout << "Sprite sheet loaded.\nTime to slice n' dice." << std::endl;
        int count = 0;
        //Pull tile size and store it
        sf::Vector2f size = *t->GetTileSize();
        
        float sizeX = s.getSize().x / size.x;
        float sizeY = s.getSize().y / size.y;
        
        //Setup source rectangle
        sf::Rect<int> r;
        r.width = size.x;
        r.height = size.y;
        

        for(int y = 0; y < sizeY; y++)
        {
              for(int x = 0; x < sizeX; x++)
              {
                  sf::Texture texture;
                  r.top = y * size.y;
                  r.left = x * size.x;
                  texture.loadFromImage(s,r);
                  //std::cout << "Slicing at X:" <<r.left <<" Y:" << r.top << std::endl;
                  count++;
                  t->AddTexture(&texture);
              
              }        
        }
        
        std::cout << count << " textures loaded." << std::endl;
        
    
    }else
    {
        std::cout << "Failed to load \""<< t->GetImageSource() << "\"." << std::endl;
    }
    
}
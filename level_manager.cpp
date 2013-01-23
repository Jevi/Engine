#include "level_manager.h"

LevelManager* LevelManager::instance;

LevelManager* LevelManager::GetInstance()
{
    if (!instance)
    {
        instance = new LevelManager;
    }
    return instance;
}

void LevelManager::Destroy()
{

}

void LevelManager::LoadLevel(int Level)
{
    string filename = GetLevelEntitiesXML(Level) + "/entities.xml";

    XMLDocument doc;

    if (doc.LoadFile(filename.c_str()) != XML_SUCCESS)
    {
        Debug::Log("Could Not Load: %s", filename.c_str());
        return;
    }
    Debug::Log("----- Processing: %s -----\n", filename.c_str());

    XMLNode* Tree = doc.FirstChild();
    if (Tree)
    {
        for (const XMLNode* Node = Tree->FirstChild(); Node; Node = Node->NextSibling())
        {
            const XMLElement* Element = Node->ToElement();
            if (strcmp(Element->Name(), "Entity") == 0)
            {
                ProcessEntity(Node);
            }
        }
    }
    Debug::Log("----- Finished Processing: %s -----\n", filename.c_str());
}

void LevelManager::ProcessEntity(const XMLNode* EntityNode)
{
    AssetLoader* assetLoader = AssetLoader::GetInstance();
    const XMLElement* entityElement = EntityNode->ToElement();
    Entity* entity = 0;
    string name;
    float posx;
    float posy;
    float rot;
    float scale;
    bool canAdd = true;

    do
    {
        if (entityElement->Attribute("id") == NULL)
        {
            break;
        }
        if (entityElement->Attribute("x") == NULL)
        {
            break;
        }
        if (entityElement->Attribute("y") == NULL)
        {
            break;
        }
        if (entityElement->Attribute("rot") == NULL)
        {
            break;
        }
        if (entityElement->Attribute("scale") == NULL)
        {
            break;
        }

        name = string((entityElement->Attribute("id")));
        posx = (float) atof(entityElement->Attribute("x"));
        posy = (float) atof(entityElement->Attribute("y"));
        rot = (float) atof(entityElement->Attribute("rot"));
        scale = (float) atof(entityElement->Attribute("scale"));

        entity = new Entity(name, posx, posy, rot, scale);

        // Process Components
        for (const XMLNode* componentNode = EntityNode->FirstChild(); componentNode; componentNode = componentNode->NextSibling())
        {
            const XMLElement* componentElement = componentNode->ToElement();
            if (strcmp(componentElement->Name(), "Component") == 0)
            {
                Component* component = 0;
                string id;
                int type;
                bool enabled;

                do
                {
                    if (componentElement->Attribute("id") == NULL)
                    {
                        break;
                    }
                    if (componentElement->Attribute("type") == NULL)
                    {
                        break;
                    }
                    if (componentElement->Attribute("enabled") == NULL)
                    {
                        break;
                    }

                    id = string(componentElement->Attribute("id"));
                    type = atoi(componentElement->Attribute("type"));
                    enabled = (atoi(componentElement->Attribute("enabled")) != 0);

                    // Process Asset
                    const XMLElement* assetElement = componentNode->FirstChild()->ToElement();
                    Asset* asset = 0;
                    string id(assetElement->Attribute("id"));
                    asset = assetLoader->GetAsset(id);
                    Debug::Log("Loaded:\n%s", asset->ToString().c_str());
                    // process Asset

                    switch (type)
                    {
                    case Component::RENDER:
                        component = new RenderComponent(name, (Sprite*) asset, enabled);
                        break;
                    case Component::AUDIO:
                        break;
                    }
                    entity->AddComponent(component);
                }
                while (0);
            }
        }// process components

        for (unsigned int i = 0; i < entities.size(); i++)
        {
            if (strcmp(entity->GetName().c_str(), entities[i]->GetName().c_str()) == 0)
            {
                canAdd = false;
            }
        }

        if (canAdd)
        {
            Debug::Log("Loaded:\n%s", entity->ToString().c_str());
            entities.push_back(entity);
        }
        else
        {
            Debug::Log("Could Not Load:\n%s", entity->ToString().c_str());
            delete entity;
        }
    }
    while (0);
}

void LevelManager::LoadNextLevel()
{
    LoadLevel(++currentLevel);
}

void LevelManager::LoadPreviousLevel()
{
    LoadLevel(--currentLevel);
}

string LevelManager::GetLevelEntitiesXML(int Level)
{
    string filename = Engine::GetProject() + "/levels/levels.xml";
    string level = Debug::NumberToString(Level);

    XMLDocument doc;

    if (doc.LoadFile(filename.c_str()) != XML_SUCCESS)
    {
        Debug::Log("Could Not Load: %s", filename.c_str());
        return NULL;
    }

    const XMLNode* tree = doc.FirstChild();
    if (tree)
    {
        for (const XMLNode* node = tree->FirstChild(); node; node = node->NextSibling())
        {
            const XMLElement* element = node->ToElement();
            if (strcmp(element->Name(), "Level") == 0)
            {
                if (strcmp(element->Attribute("num"), level.c_str()) == 0)
                {
                    return Engine::GetProject() + "/levels/" + string(element->Attribute("id"));
                }
            }
        }
    }
    return NULL;
}

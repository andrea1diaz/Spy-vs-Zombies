//
//  Coordinates.hpp
//  GAME
//
//  Created by Andrea Diaz ♡ on 10/17/18.
//  Copyright © 2018 Andrea Diaz ♡. All rights reserved.
//

#ifndef Coordinates_hpp
#define Coordinates_hpp

#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include <bitset>
#include <array>



class Component;

class Entity;

using component_id = std::size_t;

inline component_id GetComponentTypeID (){
    static component_id last_id = 0;
    return last_id ++;
}

template <typename T>
inline component_id GetComponentTypeID() noexcept {
    static component_id type_id = GetComponentTypeID();
    return type_id;
}

constexpr std::size_t max_components = 32; //modificar esto

using component_bit_set = std::bitset<max_components>;
using component_array = std::array<Component*, max_components>;


class Component {
public:
    Entity* entity;
    
    virtual void init() {};
    virtual void update() {};
    virtual void draw() {};
    
    virtual ~Component() {};
};

class Entity {
private:
    bool activate = true;
    std::vector<std::unique_ptr<Component>> components;
    
    component_array component_array;
    component_bit_set component_bit_set;
    
public:
    void update() {
        for (auto& c: components){
            c -> update();
        }
    }
    
    void draw() {
        for (auto& c: components){
            c -> draw();
        }
    }
    
    bool is_activated () {return activate;}
    
    void destroy() {activate = false;}
    
    template <typename T>
    bool HasComponent() const {
        return component_bit_set[GetComponentTypeID<T>()];
    }
    
    template <typename T, typename... TArgs>
    T& add_component(TArgs&&... mArgs) {
        T* c(new T(std::forward<TArgs>(mArgs)...));
        
        c -> entity = this;
        std::unique_ptr<Component> uPtr{ c };
        components.emplace_back(std::move(uPtr));
        
        component_array[GetComponentTypeID<T>()] = c;
        component_bit_set[GetComponentTypeID<T>()] = true;
        
        c -> init();
        
        return *c;
    }
    
    template <typename T>
    T& GetComponent() const {
        auto ptr(component_array[GetComponentTypeID<T>()]);
        return *static_cast<T*>(ptr);
    }
    
};

class Manager {
private:
    std::vector<std::unique_ptr<Entity>> entities;
    
public:
    void update() {
        for(auto& e: entities) {
            e -> update();
        }
    }
    
    void draw() {
        for(auto& e: entities) {
            e -> draw();
        }
            
    }
    
    void refresh() {
        entities.erase(std::remove_if(std::begin(entities),std::end(entities), [](const std::unique_ptr<Entity> &mEntity) {
            return !mEntity -> is_activated();
        }),
        std::end(entities));
    }
    
    
    Entity& addEntity(){
        Entity* e = new Entity();
        std::unique_ptr<Entity> uPtr{e};
        entities.emplace_back(std::move(uPtr));
        return *e;
    }
    
    
    };



#endif /* Coordinates_hpp */

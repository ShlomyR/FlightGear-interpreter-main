#pragma once

#include "Interpreter.hxx"

class Brick :public Interpreter
{
public:
    virtual void initVars();
    virtual void initSprite();
    virtual void initTexture();
    virtual void update();
    virtual void render();
   
private:
    /* data */
};

class Ball :public Interpreter
{
public:
    virtual void initVars();
    virtual void initSprite();
    virtual void initTexture();
    virtual void update();
    virtual void render();
   
private:
    /* data */
};

class Paddle :public Interpreter
{
public:
    virtual void initVars();
    virtual void initSprite();
    virtual void initTexture();
    virtual void update();
    virtual void render();
   
private:
    /* data */
    Brick* kk;
};

class Information :public Interpreter
{
public:
    virtual void initVars();
    virtual void initSprite();
    virtual void initTexture();
    virtual void update();
    virtual void render();
   
private:
    /* data */
};

void Brick::initVars()
{
}

void Brick::initSprite()
{
}

void Brick::initTexture()
{
}

void Brick::update()
{
}

void Brick::render()
{
}

void Ball::initVars()
{
}

void Ball::initSprite()
{
}

void Ball::initTexture()
{
}

void Ball::update()
{
}

void Ball::render()
{
}

void Paddle::initVars()
{
}

void Paddle::initSprite()
{
}

void Paddle::initTexture()
{
}

void Paddle::update()
{
}

void Paddle::render()
{
}

void Information::initVars()
{
}

void Information::initSprite()
{
}

void Information::initTexture()
{
}

void Information::update()
{
}

void Information::render()
{
}
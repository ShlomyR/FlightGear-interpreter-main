class Interpreter
{
public:
    virtual void initVars() = 0;
    virtual void initSprite() = 0;
    virtual void initTexture() = 0;
    virtual void update() = 0;
    virtual void render() = 0;
    virtual ~Interpreter() = default;
};
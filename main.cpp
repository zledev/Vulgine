#include <stdexcept>
#include <engine_headers.hpp>

int main()
{
    Vulgine::Engine Engine{
        {600, 600},
        "Test App",
        {1, 0, 0}};

    try
    {
        Engine.start();
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << "\n";
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
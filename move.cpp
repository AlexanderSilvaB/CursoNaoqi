#include <iostream>
#include <qi/os.hpp>
#include <alerror/alerror.h> // Include para tratar erros
#include <alproxies/almotionproxy.h> // Include para controlar os movimentos do robô
#include <alproxies/alrobotpostureproxy.h> // Include para controlar a postura do robô

using namespace std;

int main(int argc, char* argv[]) 
{
    try 
    {
        AL::ALMotionProxy motion("127.0.0.1", 9559);
        // Cria o objeto posture no robô
        AL::ALRobotPostureProxy posture("127.0.0.1", 9559);

        // "Acorda" o robô, ou seja, energiza todo o seu corpo
        motion.wakeUp();

        // Força que o robô vá para uma postura pré-definida
        posture.goToPosture("StandInit", 1.0f);

        // Seta as velocidades do robô, em metros por segundo
        float vx = 0.1f;
        float vy = 0.0f;
        float vth = 0.0f;

        // Aplica as velocidades no robô
        motion.move(vx, vy, vth);
        // Aguarda 10 segundos
        qi::os::msleep(10000);

        // Força que o robô vá para uma postura pré-definida
        posture.goToPosture("Crouch", 1.0f);

        // Para qualquer movimento que o robô estejá fazendo
        motion.killAll();

        // Desenergiza o robô
        motion.rest();
    }
    catch (const AL::ALError& e) 
    {
        cerr << "Caught exception: " << e.what() << endl;
        return 1;
    }
    return 0;
}
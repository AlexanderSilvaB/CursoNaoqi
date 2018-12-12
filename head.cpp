#include <iostream>
#include <alerror/alerror.h> // Include para tratar erros
#include <alproxies/almotionproxy.h> // Include para controlar os movimentos do robô

using namespace std;

int main(int argc, char* argv[]) 
{
    // A junta que será movida
    const AL::ALValue jointName = "HeadYaw";
    // Link para lista de juntas: http://doc.aldebaran.com/2-1/family/robots/joints_robot.html#robot-joints-v4-head-joints

    try 
    {
        // Cria o objeto motion no robô
        AL::ALMotionProxy motion("127.0.0.1", 9559);

        // Normalmente o robô não está energizado
        // Para qualquer movimento, é necessário energizar as juntas e configurar a rigidez
        AL::ALValue stiffness = 1.0f; // Definimos que a rigidez será máxima

        AL::ALValue time = 1.0f; // Definimos que a rigidez definida será alcançada em 1 segundo
        
        // Executamos o método de interpolação da rigidez
        motion.stiffnessInterpolation(jointName, stiffness, time);

        // Queremos mover a cabeça do robô, portanto definimos a lista de ângulos à serem alcançados
        AL::ALValue targetAngles = AL::ALValue::array(-1.5f, 1.5f, 0.0f);
        // Definimos também o tempo para que cada ângulo seja alcançado
        AL::ALValue targetTimes = AL::ALValue::array(3.0f, 6.0f, 9.0f);
        // Definimos que os ângulos serão absolutos, ou seja, estão referenciados ao ângulo zero
        bool isAbsolute = true;

        // Executamos o método de interpolação das juntas
        motion.angleInterpolation(jointName, targetAngles, targetTimes, isAbsolute);

        // Removemos a rigidez da cabeça
        stiffness = 0.0f;
        time = 1.0f;
        motion.stiffnessInterpolation(jointName, stiffness, time);
    }
    catch (const AL::ALError& e) 
    {
        cerr << "Caught exception: " << e.what() << endl;
        return 1;
    }
    return 0;
}
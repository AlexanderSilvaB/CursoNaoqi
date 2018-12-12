#include <iostream>
#include <alerror/alerror.h> // Include para tratar erros
#include <alproxies/altexttospeechproxy.h> // Include para utilizar o texto para voz

using namespace std;

int main(int argc, char* argv[])
{
    // Texto para o robô dizer
    const string phraseToSay = "Hello World";
    // Executa o código em um ambiente seguro, onde erros podem ser tratados
    try
    {
        // Cria o objeto text-to-speech no robô
        // O primeiro argumento é o IP do robô
        // O segundo argumento é a porta da Naoqi no robô (Padrão)
        AL::ALTextToSpeechProxy tts("127.0.0.1", 9559);

        // Chama o método say passando como parâmetro a frase que desejamos que o robô fale
        tts.say(phraseToSay);
    }
    catch (const AL::ALError& e) // Se algum erro ocorreu, mostramos o erro
    {
        cerr << "Caught exception: " << e.what() << endl;
        return 1; // Saimos do programa indicando erro
    }
    return 0;
}
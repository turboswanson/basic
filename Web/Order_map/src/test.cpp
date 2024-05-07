#include <iostream>
#include <fstream>

int main() {
    // Open an output file stream
    std::ofstream outputFile("calculator.html");

    // Write HTML content to the file
    outputFile << "<!DOCTYPE html>\n";
    outputFile << "<html>\n";
    outputFile << "<head>\n";
    outputFile << "<title>Simple Calculator</title>\n";
    outputFile << "<script>\n";
    outputFile << "function calculateSum() {\n";
    outputFile << "    var num1 = parseFloat(document.getElementById('num1').value);\n";
    outputFile << "    var num2 = parseFloat(document.getElementById('num2').value);\n";
    outputFile << "    var sum = num1 + num2;\n";
    outputFile << "    document.getElementById('result').value = sum;\n";
    outputFile << "}\n";
    outputFile << "</script>\n";
    outputFile << "</head>\n";
    outputFile << "<body>\n";
    outputFile << "<h2>Simple Calculator</h2>\n";
    outputFile << "<label for='num1'>Enter number 1:</label>\n";
    outputFile << "<input type='number' id='num1'><br><br>\n";
    outputFile << "<label for='num2'>Enter number 2:</label>\n";
    outputFile << "<input type='number' id='num2'><br><br>\n";
    outputFile << "<button onclick='calculateSum()'>Calculate Sum</button><br><br>\n";
    outputFile << "<label for='result'>Result:</label>\n";
    outputFile << "<input type='text' id='result' readonly>\n";
    outputFile << "</body>\n";
    outputFile << "</html>\n";

    // Close the output file stream
    outputFile.close();

    std::cout << "HTML file generated successfully." << std::endl;

    return 0;
}

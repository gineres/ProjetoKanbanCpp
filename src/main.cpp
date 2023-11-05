/**
 * @file main.cpp
 * @brief Programa principal para gerar um quadro de tarefas
 * @details Programa em C++ para gerar um quadro de tarefas, onde o usuário pode criar, editar, apagar e alterar a propriedade de uma tarefa.
 * @author Márcio Victor
 * @author 20210090869
 * @since 05/07/2023
 * @version 1.0
 */

#include <iostream>
#include "../include/Board.h"
#include "../include/strings.h"
#include <windows.h>

/**
 * @brief Função principal
 * @details Função principal para gerar um quadro de tarefas, onde o usuário pode criar, editar, apagar e alterar a propriedade de uma tarefa. Além disso o usuário pode salvar os dados em um arquivo, e recuperar os dados desse arquivo.
 */

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    int issueId;
    std::string issueTitle;
    std::string issueDescription;
    int issuePriority;
    int issueDifficulty;
    std::string issueDate;
    std::string issueBoard;
    int userChoice = 0;
    Board mainBoard;
    /**
     * Carrega o quadro de tarefas a partir de um arquivo, se disponível, se não, cria um novo quadro.
     */
    strings(17);
    strings(18);
    std::cin >> userChoice;
    if (userChoice == 1)
    {
        issueId = mainBoard.retrieveBoard();
    }
    /**
     * Cria uma nova tarefa no backlog, se o usuário desejar.
     */
    if (userChoice == 2)
    {
        strings(1);
        strings(2);
        std::cin.ignore();
        std::getline(std::cin, issueTitle);
        strings(3);
        std::getline(std::cin, issueDescription);
        strings(4);
        std::cin >> issuePriority;
        strings(5);
        std::cin >> issueDifficulty;
        strings(6);
        std::cin >> issueDate;
        issueId = 1;
        issueBoard = "Backlog";
        mainBoard.createIssue(issueId, issueTitle, issueDescription, issuePriority, issueDifficulty, issueDate, issueBoard);
        mainBoard.showIssue(issueId);
        strings(7);
    }
    /**
     * Menu principal do programa, onde o usuário pode escolher o que deseja fazer.
     */
    while (true)
    {
        strings(16);
        std::cin >> userChoice;
        /**
         * Cria uma nova tarefa no backlog, se o usuário desejar.
         */
        if (userChoice == 1)
        {
            strings(2);
            std::cin.ignore();
            std::getline(std::cin, issueTitle);
            strings(3);
            std::getline(std::cin, issueDescription);
            strings(4);
            std::cin >> issuePriority;
            strings(5);
            std::cin >> issueDifficulty;
            strings(6);
            std::cin >> issueDate;
            issueId = issueId + 1;
            issueBoard = "Backlog";
            mainBoard.createIssue(issueId, issueTitle, issueDescription, issuePriority, issueDifficulty, issueDate, issueBoard);
            mainBoard.showIssue(issueId);
            strings(7);
            userChoice = 0;
        }
        /**
         * Mostra os detalhes de uma tarefa, se o usuário desejar.
         */
        if (userChoice == 2)
        {
            strings(8);
            std::cin >> issueId;
            mainBoard.showIssue(issueId);
            userChoice = 0;
        }
        /**
         * Move uma tarefa de uma board para outra, se o usuário desejar.
         */
        if (userChoice == 3)
        {
            strings(9);
            std::cin >> issueId;
            strings(10);
            std::cin >> userChoice;
            if (userChoice == 1)
            {
                issueBoard = "Backlog";
            }
            if (userChoice == 2)
            {
                issueBoard = "Fazendo";
            }
            if (userChoice == 3)
            {
                issueBoard = "Em Análise";
            }
            if (userChoice == 4)
            {
                issueBoard = "Testando";
            }
            if (userChoice == 5)
            {
                issueBoard = "Em Piloto";
            }
            if (userChoice == 6)
            {
                issueBoard = "Entregue";
            }
            mainBoard.changeIssueBoard(issueId, issueBoard);
            mainBoard.printBoard();
            userChoice = 0;
        }
        /**
         * Edita uma tarefa, se o usuário desejar.
         */
        if (userChoice == 4)
        {
            strings(11);
            std::cin >> issueId;
            strings(12);
            std::cin >> userChoice;
            if (userChoice < 6)
            {
                mainBoard.editIssue(issueId, userChoice);
                mainBoard.showIssue(issueId);
            }
            userChoice = 0;
        }
        /**
         * Apaga uma tarefa, se o usuário desejar.
         */
        if (userChoice == 5)
        {
            strings(13);
            std::cin >> issueId;
            mainBoard.removeIssueFromAllBoards(issueId);
            userChoice = 0;
        }
        /**
         * Organiza as tarefas por prioridade, se o usuário desejar.
         */
        if (userChoice == 6)
        {
            mainBoard.organizeByPriority();
            strings(14);
            mainBoard.printBoard();
            userChoice = 0;
        }
        /**
         * Organiza as tarefas por dificuldade, se o usuário desejar.
         */
        if (userChoice == 7)
        {
            mainBoard.organizeByDifficulty();
            strings(15);
            mainBoard.printBoard();
            userChoice = 0;
        }
        /**
         * Imprime o quadro de tarefas, se o usuário desejar.
         */
        if (userChoice == 8)
        {
            mainBoard.printBoard();
            userChoice = 0;
        }
        /**
         * Encerra o programa e salva o estado atual do quadro de tarefas, se o usuário desejar.
         */
        if (userChoice == 9)
        {
            mainBoard.saveBoard();
            break;
        }
    }
    return 0;
}
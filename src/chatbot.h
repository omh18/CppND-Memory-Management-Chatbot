#ifndef CHATBOT_H_
#define CHATBOT_H_

#include <wx/bitmap.h>
#include <string>
#include <iostream>

class ChatLogic; // forward declaration
class GraphNode; // forward declaration

class ChatBot
{
private:
    // data handles (owned)
    wxBitmap *_image; // avatar image

    // data handles (not owned)
    GraphNode *_currentNode;
    GraphNode *_rootNode;
    ChatLogic *_chatLogic;

    // proprietary functions
    int ComputeLevenshteinDistance(std::string s1, std::string s2);

public:
    // constructors / destructors
    ChatBot();                     // constructor WITHOUT memory allocation
    ChatBot(std::string filename); // constructor WITH memory allocation
    ~ChatBot();

    //// STUDENT CODE
    ////
    ChatBot(const ChatBot& source);
    ChatBot(ChatBot&& source);

    ChatBot &operator=(const ChatBot& source){
        std::cout << "ChatBot Copy Assignment Operator" << std::endl;
	
	_chatLogic = source._chatLogic;
	_rootNode = source._rootNode;
	//_currentNode set shortly after assignment

        delete _image;

        _image = new wxBitmap(*source._image);

        return *this;
    }

    ChatBot &operator=(ChatBot&& source){
        std::cout << "ChatBot Move Assignment Operator" << std::endl;

	_chatLogic = source._chatLogic;
	_rootNode = source._rootNode;  
	//_currentNode set shortly after assignment

        delete _image;

        _image = source._image;

        // deallocate heap memory
        source._image = NULL;

        return *this;
    }
    
    wxBitmap *GetMemberImageHandle();

    GraphNode *GetCurrentNode(){ return _currentNode; }

    void initNode(GraphNode* rootNode){ _currentNode = rootNode; }
    ////
    //// EOF STUDENT CODE

    // getters / setters
    void SetCurrentNode(GraphNode *node);
    void SetRootNode(GraphNode *rootNode) { _rootNode = rootNode; }
    void SetChatLogicHandle(ChatLogic *chatLogic) { _chatLogic = chatLogic; }
    wxBitmap *GetImageHandle(){ return _image; }

    // communication
    void ReceiveMessageFromUser(std::string message);
};

#endif /* CHATBOT_H_ */

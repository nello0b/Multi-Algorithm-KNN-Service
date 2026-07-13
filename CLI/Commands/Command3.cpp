#include "Command3.h"

Command3::Command3(KnnClassifier *classifer, DefaultIO *dio)
    : Command("classify data", dio, classifer, 3){};

void Command3::execute()
{
    // Check if the classifier has any training or testing data
    if (!m_classifer->isTrain() || !m_classifer->isTest())
    {
        // If there is no data, write a message to the user
        m_dio->write("please upload data");
        return;
    }
    try
    {
        // Call the classifyData function on the classifier
        m_classifer->classifyData();
        // Write a message to the user indicating that classification is complete
        m_dio->write("classifying data complete");
    }
    catch (const exception &e)
    {
        // If an exception is thrown, write the exception message to the user
        m_dio->write(e.what());
        return;
    }
}

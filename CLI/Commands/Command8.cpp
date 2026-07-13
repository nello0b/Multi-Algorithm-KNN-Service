#include "Command8.h"

Command8::Command8(KnnClassifier *classifier, DefaultIO *dio)
    : Command("exit", dio, classifier, 8){};

void Command8::execute()
{
    // disconnect the DefaultIO
    m_dio->disconnect();
}

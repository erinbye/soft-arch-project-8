#include <iostream>
#include "..\AutomationBinding\Session.h"
#include "..\AutomationBinding\Part.h"
#include "..\AutomationBinding\Block.h"
#include "..\AutomationBinding\BlockBuilder.h"
#include "..\AutomationBinding\CADObject.h"
#include "..\AutomationBinding\FeatureCollection.h"

int main2()
{
    std::cout << "Hello World!\n";
    AutomationAPI::Session* mySession = AutomationAPI::Session::GetSession();
    AutomationAPI::Part* Part1 = mySession->MakePart("d:\\workdir\\someDir\\SomeName.part");
    Part1->MakeWidgetFeature(true, 10);
    Part1->Save();
    AutomationAPI::Part* Part2 = mySession->OpenPart("C:\\Users\\erinb\\SoftwareArchitectureCLassApplication\\SampleVersionUp.prt");

    AutomationAPI::BlockBuilder* blockBuilder1 = Part2->Features()->CreateBlockBuilder(nullptr);

    //NOTE this code will not run -- DEMO stration purposes only ---

    blockBuilder1->SetType(AutomationAPI::BlockBuilder::TypesOriginAndEdgeLengths);
    blockBuilder1->SetHeight(100);
    blockBuilder1->SetWidth(100);
    blockBuilder1->SetDepth(100);
    blockBuilder1->SetOrigin(0,0,0);
    AutomationAPI::CADObject * cadObject = blockBuilder1->Commit();
    delete blockBuilder1;
    
    AutomationAPI::Block* block1 = dynamic_cast<AutomationAPI::Block*>(cadObject);
    AutomationAPI::BlockBuilder* blockBuilder2 = Part2->Features()->CreateBlockBuilder(block1);
    std::cout << "Height: " << blockBuilder2->GetHeight() << std::endl;

    delete blockBuilder2;
    return 0;

}

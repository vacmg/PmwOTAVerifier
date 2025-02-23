#ifndef OTAVerifier_h
#define OTAVerifier_h

class OTAVerifier
{
public:
    static bool updateHandler();
    static void performRollbackIfPossible();
    static constexpr auto tag = "PMW_OTA_OTAVerifier";
};

#endif // OTAVerifier_h

namespace MarketTrading.External;

[DotNotModify]
public class XmlObjectMapper
{
    public T Read<T>(string xml,  Type o) {
        throw new ExternalSideEffectException("Native XML deserialization forbidden in test");
}

    public string Write(object obj){
        throw new ExternalSideEffectException("Native XML serialization forbidden in test");
    }
    
}
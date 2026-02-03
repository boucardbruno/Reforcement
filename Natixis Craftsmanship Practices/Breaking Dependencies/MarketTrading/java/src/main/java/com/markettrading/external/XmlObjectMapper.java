package com.markettrading.external;

@DoNotModify
public class XmlObjectMapper {

    public <T> T read(String xml, Class<T> clazz) throws ExternalSideEffectException {
        throw new ExternalSideEffectException("Native XML deserialization forbidden in test");
    }

    public String write(Object obj) throws ExternalSideEffectException {
        throw new ExternalSideEffectException("Native XML serialization forbidden in test");
    }
}

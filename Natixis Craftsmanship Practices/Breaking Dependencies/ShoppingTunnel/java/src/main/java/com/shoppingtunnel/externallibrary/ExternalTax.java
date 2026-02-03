package com.shoppingtunnel.externallibrary;

[DoNotModify]
public class ExternalTax {

    public int rate(String country) throws ExternalLibrarySideEffectError {
        throw new ExternalLibrarySideEffectError("Tax system unavailable in test");
    }
}
# Market Trading

## Context

This module is used in a **market order execution system** (front / middle office).
 It receives orders in XML, interacts with external markets via HTTP, persists transactions in the database as XML, and applies risk rules.

It is critical, legacy, and has been heavily modified over the years.

## Issues observed in production

- Orders executed at unexpected prices
- Rejections not explained by risk rules
- Different behaviors depending on the time of day
- Anomalies related to unstable market calls
- “Hot fixes” applied without tests

Teams know that bugs exist, but cannot fix them safely.

## Kata objective

- Understand a realistic trading-floor business flow
- Separate XML parsing, business decision logic, and infrastructure access
- Make the system deterministic and testable
- Identify and fix bugs after securing the system
- Set up a healthier architecture (ports/adapters)

## Rules

- ❌ Classes annotated with `@DoNotModify` must not be modified
- ❌ XML parsing, SQL, and HTTP must not be removed
- ✅ The code must be tested
- ✅ Any bug fix must be preceded by tests
- ❌ No immediate full refactoring
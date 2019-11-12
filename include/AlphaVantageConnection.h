#pragma once

#include <exception>
#include <string>
#include <json/json.h>


class RuntimeException : public std::exception
{
    public:
        RuntimeException(const std::string& error_msg) : m_error_msg(error_msg) {}
        const char* what() const throw () { return m_error_msg.c_str(); }

    private:
        std::string m_error_msg = "An Exception Occurred";
}; 


class AlphaVantageConnection
{
    private:
        AlphaVantageConnection() = default;
        ~AlphaVantageConnection() { delete m_instance; }
        static AlphaVantageConnection* m_instance;
        std::string m_api_key = "XXX";
        static const std::string DEFAULT_URL; 
        std::string TimeSeriesHelper(const std::string& series, const std::string& ticker, bool all_data) const;

    public:
        static AlphaVantageConnection* getInstance();
        void setApiKey(const std::string& api_key); 
        std::string getApiKey() const; 
        std::string GetQueryString_TIMESERIESDAILY(const std::string& ticker, bool all_data) const;
        std::string GetQueryString_TIMESERIESWEEKLY(const std::string& ticker, bool all_data) const;
        std::string GetQueryString_TIMESERIESMONTHLY(const std::string& ticker, bool all_data) const;
        std::string GetQueryString_INTRADAY(const std::string& ticker, const std::string& interval) const;
        std::string GetQueryString_GLOBALQUOTE(const std::string& ticker) const;

}; 